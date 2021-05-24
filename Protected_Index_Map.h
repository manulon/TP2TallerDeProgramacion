#ifndef PROTECTED_INDEX_MAP_H
#define PROTECTED_INDEX_MAP_H

#include <string>
#include <map>
#include <utility>

class Protected_Index_Map {
    std::map<std::string, std::pair<int,int>> internal;
    
public:
    void set_offset(const std::string& key, const int& offset);
    int get_offset(const std::string& key);
    void set_size(const std::string& key, const int& size);
    int get_size(const std::string& key);
    bool contains(const std::string& key);
    Protected_Index_Map();
    ~Protected_Index_Map();
};

#endif
