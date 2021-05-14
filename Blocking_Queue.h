#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include <string>
#include <utility>


class Blocking_Queue {
    std::queue<std::pair<std::string,std::string>> my_queue;
    
public:
    Blocking_Queue();
    void push(std::string url);
    void pop();
    std::string get_next_url();
    bool is_empty();
    ~Blocking_Queue();
};

#endif
