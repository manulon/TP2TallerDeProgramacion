#include "Web_Crawler_Starter.h"
#include "Web_Crawler.h"
#include <stdio.h>
#include <unistd.h>
#include <thread>
#include <utility>

Web_Crawler_Starter:: Web_Crawler_Starter(const char* argv[]){
    this->target = argv[1];
    this->allowed = argv[2];
    this->number_of_threads = std::atoi(argv[3]);
    this->index = argv[4];
    this->pages = argv[5];
    this->seconds_to_sleep = std::atoi(argv[6]);  
}

Web_Crawler_Starter:: Web_Crawler_Starter(){}

void Web_Crawler_Starter:: start(){
    build_map_and_list();
    initialize_threads();
    spawn_threads();
}

void Web_Crawler_Starter:: build_map_and_list(){
    this->fr.read_file_and_build_map
        (this->index,this->index_map);

    this->fr.read_file_and_build_list
        (this->target,this->target_list);
}

void Web_Crawler_Starter:: initialize_threads(){
    for (int i = 0; i < this->number_of_threads; i++) {
        std::thread new_thread;
        this->threads.insert(this->threads.end(),std::move(new_thread));
    }
}

void Web_Crawler_Starter:: spawn_threads(){
    Web_Crawler wc(this->pages,this->allowed,
        this->target_list,std::move(this->index_map));

    for (std::list<std::thread>::iterator it = this->threads.begin();
             it != this->threads.end(); ++it) {
        (*it) = std::thread([&]{ wc.start(); });
    }

    sleep(this->seconds_to_sleep);
    wc.close_queue();

    for ( auto& th: threads ){
        th.join();
    }
}

Web_Crawler_Starter:: ~Web_Crawler_Starter(){}
