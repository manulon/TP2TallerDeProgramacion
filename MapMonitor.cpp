#include "MapMonitor.h"

MapMonitor:: MapMonitor() {}

bool MapMonitor:: contains(std::string key) {
    return this->map.contains(key);
}

void MapMonitor:: putIfAbsent(std::string key, int offset,int length) {
    if (!contains(key)) {
        this->map.set_offset(key,offset);
        this->map.set_size(key,length);
   }
}

bool MapMonitor:: contains_key(std::string key){
    return this->map.contains(key);
}

int MapMonitor:: getOffsetIfPresent(std::string key){
    if (contains(key)) {
        return this->map.get_offset(key);
    }
    return 0;
}

int MapMonitor:: getSizeIfPresent(std::string key){
    if (contains(key)) {
        return this->map.get_size(key);
    }
    return 0;
}

MapMonitor:: ~MapMonitor() {}
