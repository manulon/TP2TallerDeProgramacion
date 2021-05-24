#ifndef MAP_MONITOR_H
#define MAP_MONITOR_H

#include <iostream>
#include <string>
#include <map>
#include <mutex>
#include "Protected_Map.h"

class Map_Monitor {
private:
    Protected_Map map;
    std::mutex m;
    bool contains(const std::string& key);

public:
    void putIfAbsent
    (const std::string& key, const int& value1,const int& value2);
    bool contains_key(const std::string& key);
    int getOffsetIfPresent(const std::string& key);
    int getSizeIfPresent(const std::string& key);
    void setStateIfPresent(const std::string& key,std::string state);
    void print_all_values();
    Map_Monitor();
    ~Map_Monitor();
};

#endif
