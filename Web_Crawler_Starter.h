#ifndef WEB_CRAWLER_STARTER_H
#define WEB_CRAWLER_STARTER_H

#include <iostream>
#include <thread>
#include <string>
#include "MapMonitor.h"
#include "File_Reader.h"
#include "List_Monitor.h"

class Web_Crawler_Starter {
    std::string target;
    std::string allowed;
    int number_of_threads;
    std::list<std::thread> threads;
    std::string index;
    std::string pages;
    int seconds_to_sleep;
    MapMonitor index_map;
    File_Reader fr;
    List_Monitor target_list;

    private:
        void build_map_and_list();
        void initialize_threads();
        void spawn_threads();

    public:
        Web_Crawler_Starter();
        explicit Web_Crawler_Starter(const char* argv[]);
        void start();
        ~Web_Crawler_Starter();
};

#endif
