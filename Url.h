#ifndef URL_H
#define URL_H

#include <string>
#include "State.h"

using namespace std;

class Url {
   
    State actual_state;

public:
    Url();
    const char* get_status();
    ~Url();
};

#endif