#include "Web_Crawler.h"
#include "ClosedQueueExcepcion.h"
#include <unistd.h>
#include <utility>

Web_Crawler:: Web_Crawler(const char* argv[]){
    this->target = argv[1];
    this->allowed = argv[2];
    this->number_of_threads = std::atoi(argv[3]);
    this->index = argv[4];
    this->pages = argv[5];
    this->seconds_to_sleep = std::atoi(argv[6]);
}

void Web_Crawler:: build_map_and_list(){
    this->fr.read_file_and_build_map
        (this->index,this->index_map);

    this->fr.read_file_and_build_list
        (this->target,this->target_list);
}

void Web_Crawler:: initialize_threads(){
    for (int i = 0; i < this->number_of_threads; i++) {
        std::thread new_thread;
        this->threads.insert(this->threads.end(),std::move(new_thread));
    }
}

void Web_Crawler:: spawn_threads(){
    for (std::list<std::thread>::iterator it = this->threads.begin();
             it != this->threads.end(); ++it) {
        (*it) = std::thread([&]{ start(); });
    }

    sleep(this->seconds_to_sleep);
    close_queue();

    for ( auto& th: threads ){
        th.join();
    }
}

void Web_Crawler:: search_new_urls(int offset, int size){
    std::unique_lock<std::mutex> lk(this->m);
    char* buffer = NULL;
    buffer = (char *)calloc(size+1,sizeof(char));

    std::ifstream myfilepages;
    myfilepages.open(this->pages);

    myfilepages.seekg(offset);
    myfilepages.read(buffer,size);

    std::string str(buffer);
           
    std::istringstream iss(str);
    std::string word = "";
    while (iss >> word) {
        if ( (word.find(this->allowed) != std::string::npos) &
            (word.find("http://") != std::string::npos) ){
                this->queue.push(word);
            }
    }
    free(buffer);
    myfilepages.close();
}

void Web_Crawler:: put_initial_values_in_queue(){
    for (std::list<std::string>::iterator it = this->target_list.begin();
             it != this->target_list.end(); ++it){
        this->queue.push(*it);
    }
    this->target_list.clear();
}

void Web_Crawler:: print(){
    std::unique_lock<std::mutex> lk(this->m);
    for (auto const &pair: this->final_map) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }
}

void Web_Crawler:: url_was_processed(std::string url){
    std::unique_lock<std::mutex> lk(this->m);
    this->final_map[url] = "explored";
}

void Web_Crawler:: url_was_not_processed(std::string url){
    std::unique_lock<std::mutex> lk(this->m);
    this->final_map[url] = "dead";
}

void Web_Crawler:: start(){
    put_initial_values_in_queue();

    bool keep_working = true;

    while (keep_working) {
        try{
            std::string next_url = "";
            next_url = this->queue.pop();
            if ( this->index_map.contains_key(next_url) ) {
                int offset = 
                    this->index_map.getOffsetIfPresent(next_url);
                int size   = 
                    this->index_map.getSizeIfPresent(next_url);

                search_new_urls(offset,size);
                
                url_was_processed(next_url);
            }else{
                url_was_not_processed(next_url);
            }
        } catch (ClosedQueueException &error){
            keep_working = false;
        }
    }
}

void Web_Crawler:: close_queue(){
    this->queue.close();
}

void Web_Crawler:: run(){
    build_map_and_list();
    initialize_threads();
    spawn_threads();
    print();
}

Web_Crawler:: ~Web_Crawler(){}
