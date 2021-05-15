#include "List_Monitor.h"

#include <algorithm>

List_Monitor:: List_Monitor(){}

void List_Monitor:: addIfAbsent(std::string new_element){
    if (!contains(new_element)) {
        this->list.insert(this->list.end(),new_element);
   }
}

bool List_Monitor:: contains(std::string new_element){
    return 
        std::find(this->list.begin(),this->list.end(),new_element) 
            != this->list.end();
}

void List_Monitor:: clear(){
    this->list.clear();
}

std::list<std::string>::iterator List_Monitor:: begin(){
    return this->list.begin();
}

std::list<std::string>::iterator List_Monitor:: end(){
    return this->list.end();
}

List_Monitor::~List_Monitor(){}
