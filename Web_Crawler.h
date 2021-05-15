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
#include "MapMonitor.h"
#include "File_Reader.h"
#include "List_Monitor.h"
#include "Blocking_Queue.h"

class Web_Crawler {
    std::string target;
    std::string allowed;
    int number_of_threads;
    std::string index;
    std::string pages;
    int seconds_to_sleep;
    std::list<std::thread> threads;
    MapMonitor index_map;
    File_Reader fr;
    List_Monitor target_list;
    Blocking_Queue queue;
    std::mutex m;
    std::map< std::string, std::string > final_map;


    private:
        void build_map_and_list();
        void initialize_threads();
        void spawn_threads();
        void search_new_urls(int offset, int size);
        void put_initial_values_in_queue();
        void print();
        void url_was_processed();
        void url_was_not_processed();

    public:
        Web_Crawler();
        explicit Web_Crawler(const char* argv[]);
        void start();
        void run();
        void close_queue();
        ~Web_Crawler();
};

#endif
