#include "Protected_Index_Map.h"

Protected_Index_Map:: Protected_Index_Map() {}

void Protected_Index_Map:: set_offset
(const std::string& key,const int& offset){
    this->internal[key].first = offset;
}

void Protected_Index_Map:: set_size
(const std::string& key,const int& size){
    this->internal[key].second = size;
}

int Protected_Index_Map:: get_offset(const std::string& key) {
    return this->internal.at(key).first;
}

int Protected_Index_Map:: get_size(const std::string& key) {
    return this->internal.at(key).second;
}

bool Protected_Index_Map:: contains(const std::string& key) {
    return this->internal.find(key) != this->internal.end();
}

Protected_Index_Map:: ~Protected_Index_Map() {}
