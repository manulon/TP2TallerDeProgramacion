    #include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <mutex>
#include <thread>
#include <string>
#include "Protected_Index_Map.h"
#include "MapMonitor.h"
#include "Url.h"
#include "Blocking_Queue.h"
#include "File_Reader.h"
#include "List_Monitor.h"
#include <string.h>


using namespace std;

void usingTheGoodMonitor(char const* argv[]) {
    
    MapMonitor map;
    File_Reader file_reader(argv[4],argv[1]);

    file_reader.read_file_and_build_map(&map);

    List_Monitor list;

    file_reader.read_file_and_build_list(&list);


/*
    Blocking_Queue queue;

    queue.push(url2);
 
    string allowed = argv[2];

    ifstream myfilepages;
    myfilepages.open(argv[5]);

    int offset = mapa.getOffsetIfPresent(queue.get_next_url().get_url());
    int size   = mapa.getSizeIfPresent(queue.get_next_url().get_url());

    int bytes_to_read = size - offset ;

    char* buffer = NULL;
    buffer = (char *)calloc(bytes_to_read+1,sizeof(char));

    myfilepages.read(buffer,bytes_to_read);

    string str(buffer);
    
    istringstream iss(str);
    string word;
    while(iss >> word) {
        if (word.find(allowed) != std::string::npos) {
            Url url(word);
            queue.push(url);
        }
    }
    
    map<string,string> finalmap;

    while( !queue.is_empty() ){
        if(mapa.contains_key(queue.get_next_url().get_url())){
            finalmap.emplace(queue.get_next_url().get_url(),"explored");
        }else{
            finalmap.emplace(queue.get_next_url().get_url(),"dead");
        }

        cout << queue.get_next_url().get_url() + " -> " + finalmap.at(queue.get_next_url().get_url()) << endl;
    
        queue.pop();
    }

    myfile.close();
    myfiletarget.close();
    myfilepages.close();
*/

}
   
int main(int argc, char const *argv[]) {
    usingTheGoodMonitor(argv);
    return 0;
}