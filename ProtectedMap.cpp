#include "ProtectedMap.h"

ProtectedMap:: ProtectedMap() {}

void ProtectedMap:: put(string key, int offset, int length) {
    this->internal.emplace(key, make_pair(offset,length));
}

int ProtectedMap:: get_offset(string key) {
    return this->internal.at(key).first;
}

int ProtectedMap:: get_size(string key) {
    return this->internal.at(key).second;
}

bool ProtectedMap:: contains(string key) {
    return this->internal.find(key) != this->internal.end();
}

void ProtectedMap:: remove(string key) {
    this->internal.erase(key);
}

ProtectedMap:: ~ProtectedMap() {}
