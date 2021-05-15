#include "Web_Crawler.h"
#include "ClosedQueueExcepcion.h"

Web_Crawler:: Web_Crawler(){}

Web_Crawler:: Web_Crawler
(const std::string& filename, const std::string& allowed,
const List_Monitor& list,const MapMonitor& map){
    this->filename_pages = filename;
    this->allowed = allowed;
    //this->index_map = map;
    this->target_list = list;
    myfilepages.open(filename);
}

void Web_Crawler:: put_initial_values_in_queue(){
    for (std::list<std::string>::iterator it = this->target_list.begin();
             it != this->target_list.end(); ++it){
        this->queue.push(*it);
    }
    this->target_list.clear();
}

void Web_Crawler:: start(){
    put_initial_values_in_queue();

    bool keep_working = true;

    while (keep_working) {
        try{
            if ( this->index_map.contains_key(this->queue.get_next_url()) ) {
                int offset = 
                    this->index_map.getOffsetIfPresent(this->queue.get_next_url());
                int size   = 
                    this->index_map.getSizeIfPresent(this->queue.get_next_url());

                search_new_urls(offset,size);
                
                url_was_processed();
            }else{
                url_was_not_processed();
            }
        } catch (ClosedQueueException &error){
            keep_working = false;
        }
    }

    print();
}

void Web_Crawler:: search_new_urls(int offset, int size){
    std::unique_lock<std::mutex> lk(this->m);
    char* buffer = NULL;
    buffer = (char *)calloc(size+1,sizeof(char));
            
    this->myfilepages.seekg(offset);
    this->myfilepages.read(buffer,size);

    std::string str(buffer);
           
    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
        if ( (word.find(this->allowed) != std::string::npos) &
            (word.find("http://") != std::string::npos) ){
                this->queue.push(word);
            }
    }
    free(buffer);
}

void Web_Crawler:: print(){
    std::unique_lock<std::mutex> lk(this->m);
    for (auto const &pair: this->final_map) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }
}

void Web_Crawler:: url_was_processed(){
    std::unique_lock<std::mutex> lk(this->m);
    this->final_map[this->queue.pop()] = "explored";
}

void Web_Crawler:: url_was_not_processed(){
    std::unique_lock<std::mutex> lk(this->m);
    this->final_map[this->queue.pop()] = "dead";
}

void Web_Crawler:: close_queue(){
    this->queue.close();
}

Web_Crawler:: ~Web_Crawler(){
    myfilepages.close();
}
