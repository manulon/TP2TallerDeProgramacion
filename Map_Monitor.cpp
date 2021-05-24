#include "Map_Monitor.h"

Map_Monitor:: Map_Monitor() {}

bool Map_Monitor:: contains(const std::string& key) {
    return this->map.contains(key);
}

void Map_Monitor:: putIfAbsent
(const std::string& key,const int& offset,const int& length) {
    std::unique_lock<std::mutex> lk(this->m);
    if (!contains(key)) {
        this->map.set_offset(key,offset);
        this->map.set_size(key,length);
   }
}

bool Map_Monitor:: contains_key(const std::string& key){
    std::unique_lock<std::mutex> lk(this->m);
    return this->map.contains(key);
}

int Map_Monitor:: getOffsetIfPresent(const std::string& key){
    std::unique_lock<std::mutex> lk(this->m);
    if (contains(key)) {
        return this->map.get_offset(key);
    }
    return 0;
}

void Map_Monitor:: setStateIfPresent(const std::string& url,std::string state){
    std::unique_lock<std::mutex> lk(this->m);
    if (contains(url)) 
        this->map.set_state(url,state);
}

int Map_Monitor:: getSizeIfPresent(const std::string& key){
    std::unique_lock<std::mutex> lk(this->m);
    if (contains(key)) {
        return this->map.get_size(key);
    }
    return 0;
}

void Map_Monitor:: print_all_values(){
    this->map.print_all_values();
}

Map_Monitor:: ~Map_Monitor() {}
