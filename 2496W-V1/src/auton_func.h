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

void cataAuton(int triballs)
{
    int count = 0;
    while (count<triballs)
    {
    cata.move(-127);
    bool cataCheck = cataLimit.get_value();

    }
}

#endif