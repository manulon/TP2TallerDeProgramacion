#include "Page.h"

Page:: Page(): state(),offset(),size(){}

void Page:: set_state(const std::string& state){
    this->state = state;
}

std::string Page:: get_state(){
    return this->state;
}

void Page:: set_offset(const int& offset){
    this->offset = offset;
}

int Page:: get_offset(){
    return this->offset;
}

void Page:: set_size(const int& size){
    this->size = size;
}

int Page:: get_size(){
    return this->size;
}

Page:: ~Page(){}
