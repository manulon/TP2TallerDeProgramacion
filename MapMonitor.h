#ifndef MAP_MONITOR_H
#define MAP_MONITOR_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class MapMonitor {
private:
    map<string, pair<int,int>> internal;

    bool contains(string key);

public:
    void putIfAbsent(string key, int value1, int value2);
    void printIfPresent(string key);
    void removeIfPresent(string key);
    MapMonitor();
    ~MapMonitor();
};

#endif
