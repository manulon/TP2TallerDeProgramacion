#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include "Url.h"

using namespace std;

class Blocking_Queue {
    queue<Url> my_queue;
    
public:
    Blocking_Queue();
    void push(Url url);
    void pop();
    Url get_next_url();
    bool is_empty();
    ~Blocking_Queue();
};

#endif