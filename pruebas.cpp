#include <iostream>
#include <fstream>
#include <map>
#include <mutex>
#include <thread>
#include <string>
#include "ProtectedMap.h"
#include "MapMonitor.h"

using namespace std;

void usingTheGoodMonitor(char const* argv) {
    MapMonitor map;
   
    ifstream myfile;
    myfile.open(argv);

    string url;
    string line;
    int a;
    int b;

    myfile >> url >> hex >> a >> hex >> b;
    while( getline(myfile,line) ){
        map.putIfAbsent(url,a,b);
        map.printIfPresent(url);   
        myfile >> url >> hex >> a >> hex >> b;     
    }

    myfile.close();
}
   
int main(int argc, char const *argv[]) {
    usingTheGoodMonitor(argv[1]);
    return 0;
}