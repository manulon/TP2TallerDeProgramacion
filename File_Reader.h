#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <map>
#include "Index_Map_Monitor.h"
#include "List_Monitor.h"

class File_Reader {
private:
    std::ifstream myfile_index;
    std::ifstream myfile_target;

public:
    File_Reader();
    void read_file_and_build_map
        (const std::string& filename, Index_Map_Monitor& map);
    void read_file_and_build_list
        (const std::string& filename, List_Monitor& list);
    ~File_Reader();
};

#endif
