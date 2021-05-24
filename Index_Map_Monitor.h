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
    bool contains(const std::string& key);

public:
    void putIfAbsent(const std::string& key, const int& value1,const int& value2);
    bool contains_key(const std::string& key);
    int getOffsetIfPresent(const std::string& key);
    int getSizeIfPresent(const std::string& key);
    Index_Map_Monitor();
    ~Index_Map_Monitor();
};

#endif
