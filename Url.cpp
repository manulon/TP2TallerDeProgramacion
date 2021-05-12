#include "Url.h"
#include <iostream>

Url:: Url(string url) {
    this->actual_state = "ready";
    this->url = url;
}

string Url:: get_status(){
    return this->actual_state;
}

void Url:: set_state(const string& new_state){
    this->actual_state = std::move(new_state);
    //cout << this->get_url() << " -> " << this->get_status() << endl;
}

string Url:: get_url(){
    return this->url;
}

Url:: ~Url() {}