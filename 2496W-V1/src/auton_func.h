#ifndef __AUTFUNC__
#define __AUTFUNC__

#include "main.h"
#include "global.h"


#include "pros/misc.h"
#include "pros/rtos.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iostream>

using namespace pros;
using namespace std;
using namespace glb;

void matchload(int triballs)
{
    int count = 0;
    bool cataCheck;
    while (count <= triballs)
    {
        cata.move(-127);
        cataCheck = cataLimit.get_value();
        if (cataCheck == true){
            count += 1;
            delay(300);
            
        }

    }
    cataCheck = cataLimit.get_value();
    while (!cataCheck){
        cata.move(-127);
        cataCheck = cataLimit.get_value();
    }
    cata.move(0);
}

#endif