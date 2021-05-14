#include "Web_Crawler.h"

Web_Crawler:: Web_Crawler
(const std::string& filename, const std::string& allowed,
List_Monitor* list, MapMonitor* map){
    this->filename_pages = filename;
    this->allowed = allowed;
    this->index_map = *map;
    this->target_list = *list;
    myfilepages.open(filename);
}

void Web_Crawler:: put_initial_values_in_queue(){
    for (std::list<std::string>::iterator it = this->target_list.begin();
             it != this->target_list.end(); ++it){
        this->queue.push(*it);
    }
}

void Web_Crawler:: start(){
    while ( !(this->queue.is_empty()) ){
        if ( this->index_map.contains_key(this->queue.get_next_url()) ) {
            int offset = 
                this->index_map.getOffsetIfPresent(this->queue.get_next_url());
            int size   = 
                this->index_map.getSizeIfPresent(this->queue.get_next_url());

            char* buffer = NULL;
            buffer = (char *)calloc(size+1,sizeof(char));
            
            myfilepages.seekg(offset);
            myfilepages.read(buffer,size);

            std::string str(buffer);
            
            std::istringstream iss(str);
            std::string word;
            while (iss >> word) {
                if ( (word.find(allowed) != std::string::npos) &
                     (word.find("http://") != std::string::npos) ){
                    this->queue.push(word);
                }
            }
            this->final_map[this->queue.get_next_url()] = "explored";
            this->queue.pop();
            free(buffer);
        }else{
            this->final_map[this->queue.get_next_url()] = "dead";
            this->queue.pop();
        }
    }
    for (auto const &pair: this->final_map) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }
}

Web_Crawler:: ~Web_Crawler(){
    myfilepages.close();
}
