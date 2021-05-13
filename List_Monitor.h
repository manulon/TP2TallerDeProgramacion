#ifndef LIST_MONITOR_H
#define LIST_MONITOR_H

#include <iostream>
#include <string>
#include <list>


class List_Monitor {
private:
    //Protected_Index_Map map;
    std::list<std::string> list;
public:
    List_Monitor();
    void addIfAbsent(std::string new_element);
    bool contains(std::string new_element);
    ~List_Monitor();
};

#endif