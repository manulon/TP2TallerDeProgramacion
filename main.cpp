#include "Web_Crawler.h"
#include "FileIsNotOpenException.h"

int main(int argc, char const *argv[]) {
    if (argc != 7){ return -1; }
    
    try{
        Web_Crawler wc(argv);
        wc.start();
    }catch (FileIsNotOpenException& error){
        std::cout<<error.what()<<std::endl;
        return 1;
    }

    return 0;
}
