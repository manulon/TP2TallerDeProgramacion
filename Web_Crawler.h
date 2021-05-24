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

class Web_Crawler {
    int number_of_threads;
    std::string pages;
    int seconds_to_sleep;
    std::vector<std::thread> threads;
    Map_Monitor index_map;
    File_Reader fr;
    std::list<std::string> target_list;
    Blocking_Queue queue;
    Map_Monitor final_map;
    Page_Fetcher fetcher;


    private:
        void build_map_and_list();
        void spawn_threads();
        void search_new_urls(const int& offset,const int& size);
        void put_initial_values_in_queue();
        void print();
        void page_was_processed(Page page);
        void page_was_not_processed(Page page);

    public:
        Web_Crawler();
        explicit Web_Crawler(const char* argv[]);
        void start();
        void run();
        void close_queue();
        ~Web_Crawler();
};

#endif
