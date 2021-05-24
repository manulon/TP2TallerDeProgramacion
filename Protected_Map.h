#ifndef PROTECTED_MAP_H
#define PROTECTED_MAP_H

#include "Page.h"
#include <string>
#include <map>
#include <utility>

class Protected_Map {
    std::map<std::string, Page> internal;
    
public:
    void set_offset(const std::string& key, const int& offset);
    int get_offset(const std::string& key);
    void set_size(const std::string& key, const int& size);
    int get_size(const std::string& key);
    bool contains(const std::string& key);
    void set_state(const std::string& key, const std::string& state);
    std::string get_state(const std::string& key);
    void print_all_values();
    Protected_Map();
    ~Protected_Map();
};

#endif
