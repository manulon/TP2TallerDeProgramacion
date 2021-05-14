#include "File_Reader.h"

File_Reader:: File_Reader(){}

File_Reader:: File_Reader(const std::string& index, const std::string& target){
    this->filename_index = index;
    this->filename_target = target;
    this->myfile_index.open(filename_index);
    this->myfile_target.open(filename_target);
}

void File_Reader:: read_file_and_build_map(MapMonitor* map){
    std::string url, line;
    int a, b;

    this->myfile_index >> url >> std::hex >> a >> std::hex >> b;
    while ( getline(this->myfile_index,line) ){
        map->putIfAbsent(url,a,b);
        this->myfile_index >> url >> std::hex >> a >> std::hex >> b;     
    }
}

void File_Reader:: read_file_and_build_list(List_Monitor* list){
    std::string url;

    while ( getline(this->myfile_target,url) ){
        list->addIfAbsent(url);
    }
}

File_Reader:: ~File_Reader(){
    this->myfile_index.close();
    this->myfile_target.close();
}
