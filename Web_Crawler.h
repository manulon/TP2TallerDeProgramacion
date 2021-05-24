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
#include "Index_Map_Monitor.h"
#include "Final_Map_Monitor.h"
#include "File_Reader.h"
#include "Blocking_Queue.h"

class Web_Crawler {
    std::string allowed;
    int number_of_threads;
    std::string pages;
    int seconds_to_sleep;
    std::vector<std::thread> threads;
    Index_Map_Monitor index_map;
    File_Reader fr;
    std::list<std::string> target_list;
    Blocking_Queue queue;
    Final_Map_Monitor final_map;


    private:
        void build_map_and_list();
        void spawn_threads();
        void search_new_urls(int offset, int size);
        void put_initial_values_in_queue();
        void print();
        void url_was_processed(std::string& url);
        void url_was_not_processed(std::string& url);

    public:
        Web_Crawler();
        explicit Web_Crawler(const char* argv[]);
        void start();
        void run();
        void close_queue();
        ~Web_Crawler();
};

#endif
