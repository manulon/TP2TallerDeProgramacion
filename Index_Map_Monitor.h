#ifndef INDEX_MAP_MONITOR_H
#define INDEX_MAP_MONITOR_H

#include <iostream>
#include <string>
#include <map>
#include <mutex>
#include "Protected_Index_Map.h"

class Index_Map_Monitor {
private:
    Protected_Index_Map map;
    std::mutex m;
    bool contains(std::string key);

public:
    void putIfAbsent(std::string key, int value1, int value2);
    bool contains_key(std::string key);
    int getOffsetIfPresent(std::string key);
    int getSizeIfPresent(std::string key);
    Index_Map_Monitor();
    ~Index_Map_Monitor();
};

#endif
