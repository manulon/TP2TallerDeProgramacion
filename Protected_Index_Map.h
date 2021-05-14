#ifndef PROTECTED_INDEX_MAP_H
#define PROTECTED_INDEX_MAP_H

#include <string>
#include <map>
#include <utility>

class Protected_Index_Map {
    std::map<std::string, std::pair<int,int>> internal;
    
public:
    void set_offset(std::string key, int offset);
    int get_offset(std::string key);
    void set_size(std::string key, int size);
    int get_size(std::string key);
    bool contains(std::string key);
    Protected_Index_Map();
    ~Protected_Index_Map();
};

#endif
