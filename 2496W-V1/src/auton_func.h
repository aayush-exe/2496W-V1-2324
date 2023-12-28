#ifndef __AUTFUNC__
#define __AUTFUNC__

#include "main.h"
#include "global.h"
#include "driver.h"


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
    int time = 0;
    bool cataCheck;
    while (count <= triballs)
    {
        cata.move(-127);
        // cataCheck = cataLimit.get_value();
        // if (cataCheck == true){
        //     count += 1;
        //     print_skills(time, count);
        //     delay(300);
        //     time += 2;
        // }
        count = ((int) (abs(cata.get_position()))) / 1800;
        

    }
    int pos = ((int) (abs(cata.get_position()))) % 1800;
    while (!(1500 < pos && pos < 1590)){
        cata.move(-127);
        pos = ((int) (abs(cata.get_position()))) % 1800;
    }
    cata.move(0);
}

void matchload_time(int triballs)
{
    int count = 0;
    int time = 0;
    int perTLoad = 777;
    while (time <= (perTLoad * triballs))
    {
        cata.move(-127);
        delay(10);
        count += 10;
    }
    int pos = ((int) (abs(cata.get_position()))) % 1800;
    while (!(1500 < pos && pos < 1590)){
        cata.move(-127);
        pos = ((int) (abs(cata.get_position()))) % 1800;
    }
    cata.move(0);
}

void halfCata(){
    double pos = abs(cata.get_position());

    while (!(1500 < pos && pos < 1590)) cata.move(-127);
    cata.move(0);
}

#endif