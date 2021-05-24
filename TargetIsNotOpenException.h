#ifndef TARGET_IS_NOT_OPEN_EXCEPTION
#define TARGET_IS_NOT_OPEN_EXCEPTION

#include "FileIsNotOpenException.h"
#include <iostream>

class TargetIsNotOpenException : public FileIsNotOpenException {
    virtual const char* what() override {
        return "No se puede ingresar al archivo target \n";
    }
};

#endif
