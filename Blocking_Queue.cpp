#include "Blocking_Queue.h"

Blocking_Queue:: Blocking_Queue() {}

void Blocking_Queue:: push(std::string url){
    this->my_queue.push(std::make_pair(url,"ready"));
}

void Blocking_Queue:: pop(){
    this->my_queue.pop();
}

std::string Blocking_Queue::get_next_url(){
    std::string result = this->my_queue.front().first;
    return result;
}

bool Blocking_Queue:: is_empty(){
    return this->my_queue.empty();
}

Blocking_Queue:: ~Blocking_Queue() {}
