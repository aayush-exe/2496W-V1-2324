#ifndef __AUTON__
#define __AUTON__

#include "main.h"
#include "global.h"
#include "pid.h"
#include "auton_func.h"
#include "lib/auton_obj.h"

#include "pros/misc.h"
#include "pros/rtos.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iostream>

using namespace pros;
using namespace std;
using namespace pid;

void test()
{
    drive(1000);
    delay(500);
    turn(90);
}
void blank(){}

std::vector<Auton> autons
{
    Auton("test", test),
    Auton("NO AUTON", blank)
};

#endif