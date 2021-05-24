#ifndef PROTECTED_FINAL_MAP_H
#define PROTECTED_FINAL_MAP_H

#include <string>
#include <map>
#include <utility>

class Protected_Final_Map {
    std::map<std::string, std::string> internal;
public:
    void insert(const std::string& key, const std::string& value);
    void printAllValues();
    Protected_Final_Map();
    ~Protected_Final_Map();
};

#endif
