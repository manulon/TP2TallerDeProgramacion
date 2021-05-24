#include "File_Reader.h"
#include "IndexIsNotOpenException.h"
#include "TargetIsNotOpenException.h"

File_Reader:: File_Reader
(const std::string& index, const std::string& target):
                        myfile_index(index),
                        myfile_target(target){
    if (!(this->myfile_index.is_open()))
        throw IndexIsNotOpenException();    
    if (!(this->myfile_target.is_open()))
        throw TargetIsNotOpenException();
}

void File_Reader:: read_file_and_build_map(Map_Monitor& map){
    std::string url, line;
    int a, b;

    this->myfile_index >> url >> std::hex >> a >> std::hex >> b;
    while ( getline(this->myfile_index,line) ){
        map.putIfAbsent(url,a,b);
        this->myfile_index >> url >> std::hex >> a >> std::hex >> b;     
    }
}

void File_Reader:: read_file_and_build_list(std::list<std::string>& list){
    std::string url;
    while ( getline(this->myfile_target,url) )
        list.insert(list.end(),url);
}

File_Reader:: ~File_Reader(){
    this->myfile_index.close();
    this->myfile_target.close();
}
