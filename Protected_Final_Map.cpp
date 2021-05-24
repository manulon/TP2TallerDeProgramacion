#include "Protected_Final_Map.h"
#include <iostream>

Protected_Final_Map:: Protected_Final_Map() {}

void Protected_Final_Map:: insert
(const std::string& key, const std::string& value){
    this->internal[key] = value;
}

void Protected_Final_Map:: printAllValues(){
    for ( auto& element: internal ){
        std::cout << element.first << " -> " << element.second << std::endl;
    }
}

Protected_Final_Map:: ~Protected_Final_Map() {}
