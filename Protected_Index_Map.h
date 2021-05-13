#ifndef PROTECTED_INDEX_MAP_H
#define PROTECTED_INDEX_MAP_H

#include <string>
#include <map>

using namespace std;

class Protected_Index_Map {
    map<string, pair<int,int>> internal;
    
public:
    void put(string key, int value1, int value2);
    void set_offset(string key, int offset);
    int get_offset(string key);
    void set_size(string key, int size);
    int get_size(string key);
    bool contains(string key);
    void remove(string key);
    Protected_Index_Map();
    ~Protected_Index_Map();
};

#endif
