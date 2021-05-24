#include "Web_Crawler.h"
#include "ClosedQueueException.h"
#include <unistd.h>
#include <utility>
#include <cstddef>
#include <new>
#include <vector>
#include <iostream>

Web_Crawler:: Web_Crawler(const char* argv[]):
number_of_threads(std::stoi(argv[3])),seconds_to_sleep(std::stoi(argv[6])),
fr(argv[4],argv[1]),target_list(),fetcher(argv[5],argv[2]){
    build_map_and_list();
    this->threads.reserve(this->number_of_threads);
}

void Web_Crawler:: build_map_and_list(){
    this->fr.read_file_and_build_map
        (this->index_map);

    this->fr.read_file_and_build_list
        (this->target_list);
}

void Web_Crawler:: spawn_threads(){
    for ( int i = 0; i < this->number_of_threads; i++ ) {
        this->threads.push_back(std::thread([&]{ run(); }));
    }

    sleep(this->seconds_to_sleep);
    close_queue();

    for ( auto& th: threads ){
        th.join();
    }
}

void Web_Crawler:: search_new_urls(const int& offset,const int& size){
    this->fetcher.search_new_urls(offset,size,this->queue);
}

void Web_Crawler:: put_initial_values_in_queue(){
    for (std::list<std::string>::iterator it = this->target_list.begin();
             it != this->target_list.end(); ++it){
        Page element((*it),"ready");
        this->queue.push(element);
    }
    this->target_list.clear();
}

void Web_Crawler:: print(){
    this->final_map.print_all_values();
}

void Web_Crawler:: page_was_processed(Page page){
    page.set_state("explored");
    this->final_map.putIfAbsent(page.get_url(),0,0);
    this->final_map.setStateIfPresent(page.get_url(),page.get_state());
}

void Web_Crawler:: page_was_not_processed(Page page){
    page.set_state("dead");
    this->final_map.putIfAbsent(page.get_url(),0,0);
    this->final_map.setStateIfPresent(page.get_url(),page.get_state());
}

void Web_Crawler:: run(){
    bool keep_working = true;

    while (keep_working) {
        try{
            Page next_url;
            next_url = this->queue.pop();
            if ( this->index_map.contains_key(next_url.get_url()) ) {
                int offset = 
                    this->index_map.getOffsetIfPresent(next_url.get_url());
                int size   = 
                    this->index_map.getSizeIfPresent(next_url.get_url());

                search_new_urls(offset,size);

                page_was_processed(std::move(next_url));
            }else{
                page_was_not_processed(std::move(next_url));
            }
        } catch (ClosedQueueException &error){
            keep_working = false;
        }
    }
}

void Web_Crawler:: close_queue(){
    this->queue.close();
}

void Web_Crawler:: start(){
    put_initial_values_in_queue();
    spawn_threads();
    print();
}

Web_Crawler:: ~Web_Crawler(){}
