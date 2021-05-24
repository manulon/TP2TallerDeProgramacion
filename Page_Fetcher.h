#ifndef PAGE_FETCHER_H
#define PAGE_FETCHER_H

#include "Page.h"
#include "Blocking_Queue.h"
#include <string>
#include <fstream>
#include <mutex>

class Page_Fetcher{
    std::ifstream myfile_pages;
    std::string allowed;
    std::mutex m;

public:
    Page_Fetcher(const std::string& pages,const std::string& allowed);
    void search_new_urls
    (const int& offset,const int& size,Blocking_Queue& queue);
    ~Page_Fetcher();
};


#endif
