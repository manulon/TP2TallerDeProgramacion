#ifndef WEB_CRAWLER_H
#define WEB_CRAWLER_H

#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <mutex>
#include "Blocking_Queue.h"
#include "MapMonitor.h"
#include "List_Monitor.h"

class Web_Crawler {
private:
    Blocking_Queue queue;
    std::ifstream myfilepages;
    std::string allowed;
    std::string filename_pages;
    List_Monitor target_list;
    MapMonitor  index_map;
    std::mutex m;
    std::map< std::string, std::string > final_map;

    void search_new_urls(int offset, int size);
    void put_initial_values_in_queue();
    void print();
    void url_was_processed();
    void url_was_not_processed();

public:
    Web_Crawler();
    Web_Crawler
    (const std::string& filename, const std::string& allowed,
        const List_Monitor& list,const MapMonitor& map);
    void start();
    void close_queue();
    ~Web_Crawler();
};

#endif
