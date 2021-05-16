#include "List_Monitor.h"

#include <algorithm>

List_Monitor:: List_Monitor(){}

void List_Monitor:: addIfAbsent(std::string new_element){
    if (!contains(new_element)) {
        this->list.insert(this->list.end(),new_element);
    }
}

bool List_Monitor:: contains(std::string new_element){
    std::unique_lock<std::mutex> lk(this->m);
    return 
        std::find(this->list.begin(),this->list.end(),new_element) 
            != this->list.end();
}

void List_Monitor:: clear(){
    std::unique_lock<std::mutex> lk(this->m);
    this->list.clear();
}

std::list<std::string>::iterator List_Monitor:: begin(){
    std::unique_lock<std::mutex> lk(this->m);
    return this->list.begin();
}

std::list<std::string>::iterator List_Monitor:: end(){
    std::unique_lock<std::mutex> lk(this->m);
    return this->list.end();
}

List_Monitor::~List_Monitor(){}
