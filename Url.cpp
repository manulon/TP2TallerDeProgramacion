#include "Url.h"
#include "State_Ready.h"

Url:: Url() {
    State_Ready initial_state;
    this->actual_state = State_Ready();
}

const char* Url:: get_status(){
    return this->actual_state.get_status();
}

Url:: ~Url() {}