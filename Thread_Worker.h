#ifndef THREAD_WORKER_H
#define THREAD_WORKER_H

#include "Thread.h"
#include "Blocking_Queue.h"
#include "Map_Monitor.h"
#include "Page_Fetcher.h"
#include <string>

class Thread_Worker: public Thread{
    Blocking_Queue* queue;
    Map_Monitor* map;
    Page_Fetcher* fetcher;
    Map_Monitor* final_map;
private:
    void process_page(Page p,std::string new_state);

    public:
    Thread_Worker
    (Blocking_Queue* q, Map_Monitor* m, Page_Fetcher* f,Map_Monitor* fm);
    virtual void run() override;
    virtual ~Thread_Worker() override;
};

#endif
