#ifndef MAP_MONITOR_H
#define MAP_MONITOR_H

#include <iostream>
#include <string>
#include <map>
#include "ProtectedMap.h"

using namespace std;

class MapMonitor {
private:
    //map<string, pair<int,int>> internal;
    ProtectedMap map;

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
