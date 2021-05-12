    #include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <mutex>
#include <thread>
#include <string>
#include "ProtectedMap.h"
#include "MapMonitor.h"
#include "Url.h"
#include "Blocking_Queue.h"
#include <string.h>


using namespace std;

void usingTheGoodMonitor(char const* argv[]) {
    MapMonitor mapa;
   
    ifstream myfile;
    myfile.open(argv[4]);

    string url;
    string line;
    int a;
    int b;

    //cout << " EL INDEX TIENE " << endl;
    myfile >> url >> hex >> a >> hex >> b;
    while( getline(myfile,line) ){
        mapa.putIfAbsent(url,a,b);
        //mapa.printIfPresent(url);   
        myfile >> url >> hex >> a >> hex >> b;     
    }

    //cout << "---------------------" << endl;

    ifstream myfiletarget;
    myfiletarget.open(argv[1]);

    string urltarget;

    myfiletarget >> urltarget;

    Url url2(urltarget);
    Blocking_Queue queue;

    queue.push(url2);
    //cout << " EL TARGET TIENE " << endl;
    //cout << queue.get_next_url().get_url() << " -> " << queue.get_next_url().get_status() << endl;
    //queue.pop();

    //cout << "---------------------" << endl;

    string allowed = argv[2];

    //cout << "---------------------" << endl;

    ifstream myfilepages;
    myfilepages.open(argv[5]);

    int offset = mapa.getOffsetIfPresent(queue.get_next_url().get_url());
    int size   = mapa.getSizeIfPresent(queue.get_next_url().get_url());

    //cout << "( " << offset << ", " << size << " )" << endl;

    int bytes_to_read = size - offset ;

    //cout << "Leere: " << bytes_to_read << endl;

    char* buffer = NULL;
    buffer = (char *)calloc(bytes_to_read+1,sizeof(char));

    myfilepages.read(buffer,bytes_to_read);

    //cout << buffer << endl

    string str(buffer);
    
    istringstream iss(str);
    string word;
    while(iss >> word) {
        //cout << word << endl;
        if (word.find(allowed) != std::string::npos) {
            //cout << "found!" << word << endl;
            Url url(word);
            queue.push(url);
        }
    }

    //cout << "ACTUALMENTE LA COLA CONTIENE" << endl;
    //while( !queue.is_empty() ){
    //    cout << queue.get_next_url().get_url() + " " + queue.get_next_url().get_status() << endl;
    //   queue.pop();
    //}
    
    //cout << "---------------------" << endl;
    /*
    while( !queue.is_empty() ){
        if(map.contains_key(queue.get_next_url().get_url())){
            const string e = "explored";
            queue.get_next_url().set_state(e);
            cout << queue.get_next_url().get_url() << " -> " << queue.get_next_url().get_status() << endl;
        }else{
            const string d = "dead";
            queue.get_next_url().set_state(d);
            cout << queue.get_next_url().get_url() << " -> " << queue.get_next_url().get_status() << endl;
        }
        
        //cout << queue.get_next_url().get_url() << " -> " << queue.get_next_url().get_status() << endl;

        queue.pop();
    }*/

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
}
   
int main(int argc, char const *argv[]) {
    usingTheGoodMonitor(argv);
    return 0;
}