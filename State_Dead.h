#ifndef STATE_DEAD_H
#define STATE_DEAD_H

#include "State.h"

using namespace std;

class State_Dead: public State {

public:
    State_Dead():State(){};
    ~State_Dead();
};

#endif