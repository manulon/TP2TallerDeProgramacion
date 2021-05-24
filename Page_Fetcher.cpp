#include "Page_Fetcher.h"
#include "PagesIsNotOpenException.h"
#include <vector>
#include <sstream>

Page_Fetcher:: Page_Fetcher
(const std::string& pages,const std::string& allowed):
myfile_pages(pages),allowed(allowed){
    if (!(this->myfile_pages.is_open()))
        throw PagesIsNotOpenException();  
}

void Page_Fetcher:: search_new_urls
(const int& offset,const int& size,Blocking_Queue& queue){
    std::unique_lock<std::mutex> lk(this->m);
    std::vector<char> buffer(size+1);
    
    this->myfile_pages.seekg(offset);
    this->myfile_pages.read(buffer.data(),size);

    std::string str(buffer.data());
           
    std::istringstream iss(str);
    std::string word = "";
    while (iss >> word) {
        if ( (word.find(this->allowed) != std::string::npos) &
            (word.find("http://") != std::string::npos) ){
                Page element(word,"ready");
                queue.push(element);
            }
    }
}

Page_Fetcher:: ~Page_Fetcher(){}
