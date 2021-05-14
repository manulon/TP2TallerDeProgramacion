#include "Web_Crawler_Starter.h"
#include "Web_Crawler.h"
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
    this->fr.read_file_and_build_map
        (this->index,this->index_map);

    this->fr.read_file_and_build_list
        (this->target,this->target_list);

    Web_Crawler wc(this->pages,this->allowed,
        this->target_list,this->index_map);
    
    wc.start();
}

Web_Crawler_Starter:: ~Web_Crawler_Starter(){}
