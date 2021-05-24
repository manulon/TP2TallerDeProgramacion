#include "Protected_Map.h"
#include <iostream>

Protected_Map:: Protected_Map() {}

void Protected_Map:: set_offset
(const std::string& key,const int& offset){
    this->internal[key].set_offset(offset);
}

void Protected_Map:: set_size
(const std::string& key,const int& size){
    this->internal[key].set_size(size);
}

int Protected_Map:: get_offset(const std::string& key) {
    return this->internal.at(key).get_offset();
}

int Protected_Map:: get_size(const std::string& key) {
    return this->internal.at(key).get_size();
}

bool Protected_Map:: contains(const std::string& key) {
    return this->internal.find(key) != this->internal.end();
}

void Protected_Map:: set_state
(const std::string& key, const std::string& state){
    this->internal[key].set_state(state);
}

std::string Protected_Map:: get_state(const std::string& key){
    return this->internal.at(key).get_state();
}

void Protected_Map:: print_all_values(){
    for ( auto& element: internal ){
        std::cout << element.first << " -> " <<
        element.second.get_state() << std::endl;
    }
}


Protected_Map:: ~Protected_Map() {}
