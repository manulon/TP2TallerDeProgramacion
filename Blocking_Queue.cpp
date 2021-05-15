#include "Blocking_Queue.h"
#include "ClosedQueueExcepcion.h"

Blocking_Queue:: Blocking_Queue() {
    this->isClosed = false;
}

void Blocking_Queue:: push(std::string url){
    std::unique_lock<std::mutex> lk(this->m);
    this->my_queue.push(std::make_pair(url,"ready"));
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
    std::string first_element = this->my_queue.front().first;
    this->my_queue.pop();
    return first_element;
}

std::string Blocking_Queue::get_next_url(){
    std::unique_lock<std::mutex> lk(this->m);
    std::string result = this->my_queue.front().first;
    return result;
}

bool Blocking_Queue:: is_open(){
    std::unique_lock<std::mutex> lk(this->m);
    return this->isClosed;
}

void Blocking_Queue:: close(){
    std::unique_lock<std::mutex> lk(this->m);
    this->isClosed = true;
    this->cv.notify_all();
}

Blocking_Queue:: ~Blocking_Queue() {}
