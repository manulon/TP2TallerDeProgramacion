#ifndef STATE_H
#define STATE_H


using namespace std;

class State {
protected:
    const char* status;
    
public:
    State();
    const char* get_status();
    ~State();
};

#endif