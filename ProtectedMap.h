#ifndef PROTECTED_MAP_H
#define PROTECTED_MAP_H

#include <string>
#include <map>

using namespace std;

class ProtectedMap {
private:
    map<string, pair<int,int>> internal;
    
public:
    void put(string key, int value1, int value2);
    int get_offset(string key);
    int get_size(string key);
    bool contains(string key);
    void remove(string key);
    ProtectedMap();
    ~ProtectedMap();
};

#endif
