#include "Index_Map_Monitor.h"

Index_Map_Monitor:: Index_Map_Monitor() {}

bool Index_Map_Monitor:: contains(const std::string& key) {
    return this->map.contains(key);
}

void Index_Map_Monitor:: putIfAbsent
(const std::string& key,const int& offset,const int& length) {
    if (!contains(key)) {
        this->map.set_offset(key,offset);
        this->map.set_size(key,length);
   }
}

bool Index_Map_Monitor:: contains_key(const std::string& key){
    std::unique_lock<std::mutex> lk(this->m);
    return this->map.contains(key);
}

int Index_Map_Monitor:: getOffsetIfPresent(const std::string& key){
    std::unique_lock<std::mutex> lk(this->m);
    if (contains(key)) {
        return this->map.get_offset(key);
    }
    return 0;
}

int Index_Map_Monitor:: getSizeIfPresent(const std::string& key){
    std::unique_lock<std::mutex> lk(this->m);
    if (contains(key)) {
        return this->map.get_size(key);
    }
    return 0;
}

Index_Map_Monitor:: ~Index_Map_Monitor() {}
