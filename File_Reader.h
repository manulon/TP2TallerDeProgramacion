#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <map>
#include "MapMonitor.h"
#include "List_Monitor.h"

class File_Reader {

private:
    std::string filename_index;
    std::string filename_target;
    ifstream myfile_index;
    ifstream myfile_target;

public:
    File_Reader(const std::string index, const std::string target);
    void read_file_and_build_map(MapMonitor* map);
    void read_file_and_build_list(List_Monitor* list);
    ~File_Reader();

};

#endif