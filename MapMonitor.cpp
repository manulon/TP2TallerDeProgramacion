#include "MapMonitor.h"

MapMonitor:: MapMonitor() {}

bool MapMonitor:: contains(string key) {
    return this->map.contains(key);
}

void MapMonitor:: putIfAbsent(string key, int offset,int length) {
    if (!contains(key)) {
        this->map.set_offset(key,offset);
        this->map.set_size(key,length);
   }
}

void MapMonitor:: printIfPresent(string key) {
    if (contains(key)) {
        cout << "Par rescatado! (" << (string) key << 
        ", [" << this->map.get_offset(key) << " , " 
        << this->map.get_size(key) << "] )" << endl;
    }
}

bool MapMonitor:: contains_key(string key){
    return this->map.contains(key);
}

void MapMonitor:: removeIfPresent(string key) {
    if (contains(key)) {
        this->map.remove(key);
    }
}

int MapMonitor:: getOffsetIfPresent(string key){
    if (contains(key)) {
        return this->map.get_offset(key);
    }
    return 0;
}

int MapMonitor:: getSizeIfPresent(string key){
    if (contains(key)) {
        return this->map.get_size(key);
    }
    return 0;
}

MapMonitor:: ~MapMonitor() {}
