#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <mutex>
#include <thread>
#include <string>
#include "Protected_Index_Map.h"
#include "MapMonitor.h"
#include "Blocking_Queue.h"
#include "File_Reader.h"
#include "List_Monitor.h"
#include "Web_Crawler.h"
#include <string.h>

   
int main(int argc, char const *argv[]) {
    if (argc != 7){ return -1; }

    MapMonitor map;
    File_Reader file_reader(argv[4],argv[1]);

    file_reader.read_file_and_build_map(&map);

    List_Monitor list;

    file_reader.read_file_and_build_list(&list);

    Web_Crawler wc(argv[5],argv[2],&list,&map);

    wc.put_initial_values_in_queue();
    wc.start();

    return 0;
}
