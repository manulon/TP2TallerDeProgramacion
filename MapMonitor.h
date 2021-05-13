#ifndef MAP_MONITOR_H
#define MAP_MONITOR_H

#include <iostream>
#include <string>
#include <map>
#include "Protected_Index_Map.h"

using namespace std;

class MapMonitor {
private:
    Protected_Index_Map map;

    bool contains(string key);

public:
    void putIfAbsent(string key, int value1, int value2);
    void printIfPresent(string key);
    bool contains_key(string key);
    void removeIfPresent(string key);
    int getOffsetIfPresent(string key);
    int getSizeIfPresent(string key);
    MapMonitor();
    ~MapMonitor();
};

#endif
