#ifndef CLOSED_QUEUE_EXCEPTION_H
#define CLOSED_QUEUE_EXCEPTION_H

#include <exception>

class ClosedQueueException : public std::exception {
    public:
        const char*what() {
            return "Queue is closed";
        }
};

#endif
