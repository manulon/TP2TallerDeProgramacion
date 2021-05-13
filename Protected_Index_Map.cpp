#include "Protected_Index_Map.h"

Protected_Index_Map:: Protected_Index_Map() {}

void Protected_Index_Map:: put(string key, int offset, int length) {
    this->internal.emplace(key, make_pair(offset,length));
}

void Protected_Index_Map:: set_offset(string key, int offset){
    this->internal[key].first = offset;
}

void Protected_Index_Map:: set_size(string key, int size){
    this->internal[key].second = size;
}

int Protected_Index_Map:: get_offset(string key) {
    return this->internal.at(key).first;
}

int Protected_Index_Map:: get_size(string key) {
    return this->internal.at(key).second;
}

bool Protected_Index_Map:: contains(string key) {
    return this->internal.find(key) != this->internal.end();
}

void Protected_Index_Map:: remove(string key) {
    this->internal.erase(key);
}

Protected_Index_Map:: ~Protected_Index_Map() {}
