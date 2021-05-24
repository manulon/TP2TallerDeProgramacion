#include "Final_Map_Monitor.h"

Final_Map_Monitor:: Final_Map_Monitor() {}

void Final_Map_Monitor:: insert
(const std::string& key, const std::string& value){
    std::unique_lock<std::mutex> lk(this->m);
    this->map.insert(key,value);
}

void Final_Map_Monitor:: printAllValues(){
    this->map.printAllValues();
}

Final_Map_Monitor:: ~Final_Map_Monitor() {}
