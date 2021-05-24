#ifndef FINAL_MAP_MONITOR_H
#define FINAL_MAP_MONITOR_H

#include <iostream>
#include <string>
#include <map>
#include <mutex>
#include "Protected_Final_Map.h"

class Final_Map_Monitor {
private:
    Protected_Final_Map map;
    std::mutex m;

public:
    void insert(const std::string& key, const std::string& value);
    void printAllValues();
    Final_Map_Monitor();
    ~Final_Map_Monitor();
};

#endif