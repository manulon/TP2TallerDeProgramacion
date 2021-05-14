#include "Web_Crawler_Starter.h"
   
int main(int argc, char const *argv[]) {
    if (argc != 7){ return -1; }

    Web_Crawler_Starter wc_starter(argv);

    wc_starter.start();

    return 0;
}
