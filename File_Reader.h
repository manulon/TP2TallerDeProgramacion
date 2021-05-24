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
    File_Reader
    (const std::string& index, const std::string& target);
    void read_file_and_build_map(Index_Map_Monitor& map);
    void read_file_and_build_list(List_Monitor& list);
    ~File_Reader();
};

#endif
