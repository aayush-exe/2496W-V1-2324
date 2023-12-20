#ifndef __AUTON_OBJ__
#define __AUTON_OBJ__

#include "main.h"
#include <string>


typedef void(&fref)();
typedef void(*fptr)();

class Auton
{
private:
    std::string name;
    fptr auton;
    std::string status;

public:
    Auton(std::string init_name, fref init_auton, std::string init_status)
    {
        name = init_name;
        auton = init_auton;
        status = init_status;
    }

    void run() 
    {
        (*auton)();
    }

    std::string get_name()
    {
        return name;
    } 

    std::string get_d()
    { 
        return status;
    }
};

#endif