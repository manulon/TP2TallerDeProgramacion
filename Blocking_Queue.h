#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include "Page.h"
#include <queue>
#include <string>
#include <utility>
#include <mutex>
#include <condition_variable>


class Blocking_Queue {
    std::queue<Page> my_queue;
    std::mutex m;
    std::condition_variable cv;
    bool isClosed;
public:
    Blocking_Queue();
    void push(Page new_page);
    Page pop();
    void close();
    ~Blocking_Queue();
};

#endif
