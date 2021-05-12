#include "Blocking_Queue.h"

Blocking_Queue:: Blocking_Queue() {}

void Blocking_Queue:: push(Url url){
    this->my_queue.push(url);
}

void Blocking_Queue:: pop(){
    this->my_queue.pop();
}


Url Blocking_Queue:: get_next_url(){
    return this->my_queue.front();
}

bool Blocking_Queue:: is_empty(){
    return this->my_queue.empty();
}

Blocking_Queue:: ~Blocking_Queue() {}