#ifndef PAGES_IS_NOT_OPEN_EXCEPTION
#define PAGES_IS_NOT_OPEN_EXCEPTION

#include "FileIsNotOpenException.h"
#include <iostream>

class PagesIsNotOpenException : public FileIsNotOpenException {
    public:
        virtual const char* what() override {
            return "No se puede ingresar al archivo pages \n";
        }
};

#endif