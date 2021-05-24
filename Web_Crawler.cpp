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
        this->threads.push_back(new Thread_Worker(
        &this->queue, &this->index_map, &this->fetcher, &this->final_map));
    }
    
    for ( int i = 0; i < this->number_of_threads; i++ ) {
        this->threads[i]->start();
    }

    sleep(this->seconds_to_sleep);
    close_queue();

    for (int i = 0; i < this->number_of_threads; i++) {
        this->threads[i]->join();
        delete threads[i];
    }
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

void Web_Crawler:: close_queue(){
    this->queue.close();
}

void Web_Crawler:: start(){
    put_initial_values_in_queue();
    spawn_threads();
    print();
}

Web_Crawler:: ~Web_Crawler(){}
