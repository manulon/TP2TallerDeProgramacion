#ifndef WEB_CRAWLER_H
#define WEB_CRAWLER_H

#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include "Blocking_Queue.h"
#include "List_Monitor.h"
#include "MapMonitor.h"

class Web_Crawler {
    Blocking_Queue queue;
    std::ifstream myfilepages;
    std::string allowed;
    std::string filename_pages;
    List_Monitor target_list;
    MapMonitor  index_map;
    std::map< std::string, std::string > final_map;

public:
    Web_Crawler
    (const std::string& filename, const std::string& allowed,
        List_Monitor* list, MapMonitor* map);
    void put_initial_values_in_queue();
    void start();
    
    ~Web_Crawler();
};

#endif
