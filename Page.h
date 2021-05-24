#ifndef PAGE_H
#define PAGE_H

#include <string>

class Page{
private:
    std::string state;
    int offset;
    int size;
    
public:
    Page();
    void set_state(const std::string& state);
    std::string get_state();
    void set_offset(const int& offset);
    int get_offset();
    void set_size(const int& size);
    int get_size();
    ~Page();
};

#endif