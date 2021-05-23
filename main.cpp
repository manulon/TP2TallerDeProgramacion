#include "Web_Crawler.h"
   
int main(int argc, char const *argv[]) {
    if (argc != 7){ return -1; }
    Web_Crawler wc(argv);
    wc.start();

    return 0;
}
