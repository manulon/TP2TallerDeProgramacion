#ifndef URL_H
#define URL_H

#include <string>

using namespace std;

class Url {
    string url;
    string actual_state;

public:
    Url(string url);
    string get_status();
    string get_url();
    void set_state(const string& new_state);
    ~Url();
};

#endif