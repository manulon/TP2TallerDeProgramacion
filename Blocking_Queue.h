#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include <string>
#include <utility>
#include <mutex>
#include <condition_variable>


class Blocking_Queue {
    std::queue<std::string> my_queue;
    std::mutex m;
    std::condition_variable cv;
    bool isClosed;
public:
    Blocking_Queue();
    void push(std::string url);
    std::string pop();
    void close();
    ~Blocking_Queue();
};

#endif
