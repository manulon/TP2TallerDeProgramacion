#include "File_Reader.h"

File_Reader:: File_Reader(){}

void File_Reader:: read_file_and_build_map
(const std::string& filename, Index_Map_Monitor& map){
    this->myfile_index.open(filename);

    std::string url, line;
    int a, b;

    this->myfile_index >> url >> std::hex >> a >> std::hex >> b;
    while ( getline(this->myfile_index,line) ){
        map.putIfAbsent(url,a,b);
        this->myfile_index >> url >> std::hex >> a >> std::hex >> b;     
    }
}

void File_Reader:: read_file_and_build_list
(const std::string& filename, List_Monitor& list){
    this->myfile_target.open(filename);

    std::string url;

    while ( getline(this->myfile_target,url) ){
        list.addIfAbsent(url);
    }
}

File_Reader:: ~File_Reader(){
    this->myfile_index.close();
    this->myfile_target.close();
}
