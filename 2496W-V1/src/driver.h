#ifndef __DRIVER__
#define __DRIVER__

#include "main.h"
#include "global.h"
#include <iostream>


//using namespace pros;
using namespace glb;
//using namespace std;

void drive()
{
    double left = abs(con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) > 10 ? con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) : 0;
    double right = abs(con.get_analog(E_CONTROLLER_ANALOG_RIGHT_X)) > 10 ? con.get_analog(E_CONTROLLER_ANALOG_RIGHT_X) : 0;

    right /= 1.2;
    if(left || right)
    {
        chas.spin_left(left + right);
        chas.spin_right(left - right);
    }
    else
        chas.stop();

}

void intakeCon()
{
    if(con.get_digital(E_CONTROLLER_DIGITAL_R1)) 
		intake.move(127);
    else if(con.get_digital(E_CONTROLLER_DIGITAL_R2))
        intake.move(-127);
    else 
        intake.move(0);
}


void cataCon(int time)
{
    static bool cataPressed;
    bool cataCheck = cataLimit.get_value();
    //static bool prevCataCheck = cataCheck;
   // static bool delay_launch = false;
    
    // if (con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
    //     delay_launch = !delay_launch;

    if (con.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
        cataPressed = true;

    if (!cataCheck)
    {
        cata.move(-127);
        cataPressed = false;
    }
    else if (cataPressed && cataCheck)
    {
        cata.move(-127);
    }
    else 
        cata.move(0);


    //if(time % 50 == 0 && time % 100 != 0 && time % 150 != 0)
     //   con.print(0, 0, false ? "MATCH LOAD     " : "FULL SPEED     ");
    
    //prevCataCheck = cataCheck;
    
}

void piston_cont()
{
    if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) wingP.toggle();
    if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) intakeP.toggle();
    if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) spikeP.toggle();
}

void print_info(int time, bool chassis_on)
{
    // first line in cata func
    if(time % 100 == 0 && time % 150 != 0) 
        if (!chassis_on) con.print(0, 0, "%.1lf:%.1lf:%.1lf         ", chas.temp(), intake.get_temperature(), cata.get_temperature());
        else con.print(0, 0, "CHAS OFF (right)     ");
    if(time % 150 == 0)
        con.print(2, 0, cataLimit.get_value() ? "On     " : "Off     ");
}

#endif