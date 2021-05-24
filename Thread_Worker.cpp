#include "Thread_Worker.h"
#include "ClosedQueueException.h"


Thread_Worker:: Thread_Worker
(Blocking_Queue* q, Map_Monitor* m, Page_Fetcher* f,Map_Monitor* fm){
    this->queue = q;
    this->map = m;
    this->fetcher = f;
    this->final_map = fm;
}

void Thread_Worker:: run() {
   bool keep_working = true;

    while (keep_working) {
        try{
            Page next_url;
            next_url = this->queue->pop();
            if ( this->map->contains_key(next_url.get_url()) ) {
                int offset = 
                    this->map->getOffsetIfPresent(next_url.get_url());
                int size   = 
                    this->map->getSizeIfPresent(next_url.get_url());

                this->fetcher->search_new_urls(offset,size,*(this->queue));

                process_page(next_url,"explored");
            }else{
                process_page(next_url,"dead");
            }
        } catch (ClosedQueueException &error){
            keep_working = false;
        }
    }
}

void Thread_Worker:: process_page(Page p,std::string new_state){
    p.set_state(new_state);
    this->final_map->putIfAbsent(p.get_url(),0,0);
    this->final_map->setStateIfPresent(p.get_url(),p.get_state());
}

Thread_Worker:: ~Thread_Worker(){}
