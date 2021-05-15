#ifndef LIST_MONITOR_H
#define LIST_MONITOR_H

#include <iostream>
#include <string>
#include <list>
#include <mutex>

class List_Monitor {
private:
    std::list<std::string> list;
    std::mutex m;

public:
    List_Monitor();
    void addIfAbsent(std::string new_element);
    bool contains(std::string new_element);
    void clear();
    std::list<std::string>::iterator begin();
    std::list<std::string>::iterator end();
    ~List_Monitor();
};

#endif
