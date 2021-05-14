#ifndef MAP_MONITOR_H
#define MAP_MONITOR_H

#include <iostream>
#include <string>
#include <map>
#include "Protected_Index_Map.h"

class MapMonitor {
private:
    Protected_Index_Map map;

    bool contains(std::string key);

public:
    void putIfAbsent(std::string key, int value1, int value2);
    bool contains_key(std::string key);
    int getOffsetIfPresent(std::string key);
    int getSizeIfPresent(std::string key);
    MapMonitor();
    ~MapMonitor();
};

#endif
