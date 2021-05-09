#include "MapMonitor.h"

MapMonitor:: MapMonitor() {}

bool MapMonitor:: contains(string key) {
    return this->internal.find(key) != this->internal.end();
}

void MapMonitor:: putIfAbsent(string key, int offset,int length) {
    if (!contains(key)) {
        this->internal[key].first = offset;
        this->internal[key].second = length;
    }
}

void MapMonitor:: printIfPresent(string key) {
    if (contains(key)) {
        cout << "Par rescatado! (" << (string) key << 
        ", [" << this->internal.at(key).first << " , " 
        << this->internal.at(key).second << "] )" << endl;
    }
}

void MapMonitor:: removeIfPresent(string key) {
    if (contains(key)) {
        this->internal.erase(key);
    }
}

MapMonitor:: ~MapMonitor() {}
