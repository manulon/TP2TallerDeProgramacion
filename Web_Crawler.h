#ifndef WEB_CRAWLER_H
#define WEB_CRAWLER_H

#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <mutex>
#include <vector>
#include "Map_Monitor.h"
#include "File_Reader.h"
#include "Blocking_Queue.h"
#include "Page.h"
#include "Page_Fetcher.h"
#include "Thread_Worker.h"

class Web_Crawler {
    int number_of_threads;
    std::string pages;
    int seconds_to_sleep;
    std::vector<Thread_Worker*> threads;
    Map_Monitor index_map;
    File_Reader fr;
    std::list<std::string> target_list;
    Blocking_Queue queue;
    Map_Monitor final_map;
    Page_Fetcher fetcher;

    private:
        void build_map_and_list();
        void spawn_threads();
        void put_initial_values_in_queue();
        void print();
        
    public:
        Web_Crawler();
        explicit Web_Crawler(const char* argv[]);
        void start();
        void close_queue();
        ~Web_Crawler();
};

#endif
