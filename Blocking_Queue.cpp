#include "Blocking_Queue.h"
#include "ClosedQueueException.h"
#include <iostream>

Blocking_Queue:: Blocking_Queue() {
    this->isClosed = false;
}

void Blocking_Queue:: push(const std::string& url){
    std::unique_lock<std::mutex> lk(this->m);
    this->my_queue.push(url);
    this->cv.notify_all();
}

std::string Blocking_Queue::pop(){
    std::unique_lock<std::mutex> lk(this->m);
    while ( this->my_queue.empty() ){
        if ( this->isClosed ){
            throw ClosedQueueException();
        }
        this->cv.wait(lk);
    }
    std::string first_element = this->my_queue.front();
    this->my_queue.pop();
    return first_element;
}

void Blocking_Queue:: close(){
    std::unique_lock<std::mutex> lk(this->m);
    this->isClosed = true;
    this->cv.notify_all();
}

Blocking_Queue:: ~Blocking_Queue() {}
