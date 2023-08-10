#ifndef _DRIVER_
#define _DRIVER_

#include "main.h"
#include "global.h"
#include <iostream>


using namespace pros;
using namespace glb;
using namespace std;

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

void intake()
{
    if(con.get_digital(E_CONTROLLER_DIGITAL_R1)) 
		Intake.move(127);
    else if(con.get_digital(E_CONTROLLER_DIGITAL_R2))
        Intake.move(-127);
    else 
        Intake.move(0);
}


void cata(int time)
{
    static bool cataPressed;
    bool cataCheck = cataLimit.get_value();
    static bool prevCataCheck = cataCheck;
    static bool delay_launch = false;
    
    if (con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
        delay_launch = !delay_launch;

    if (con.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
        cataPressed = true;

    if (!cataCheck)
    {
        Cata.move(-127);
        cataPressed = false;
    }
    else if (cataPressed && cataCheck)
    {
        if (!prevCataCheck && cataCheck)
            Cata.move(0);
            delay(delay_launch ? 300 : 0);
        Cata.move(-127);
    }
    else 
        Cata.move(0);


    if(time % 50 == 0 && time % 100 != 0 && time % 150 != 0)
        con.print(0, 0, delay_launch ? "MATCH LOAD     " : "FULL SPEED     ");
    
    prevCataCheck = cataCheck;
    
}

void wings()
{
    static bool PWingsButton;
    static bool PWingsActive;
    if(con.get_digital(E_CONTROLLER_DIGITAL_L2)) 
    {
			if(!PWingsButton) 
            {
				PWingsButton = true;
				if(PWingsActive) 
                {
					PWingsActive = !PWingsActive;
					wingPiston.set_value(false);
				}
				else 
                {
					PWingsActive = !PWingsActive;
					wingPiston.set_value(true);
				}
			}
		}
    else PWingsButton = false;


}

void print_info(int time)
{
    // first line in cata func
    if(time % 100 == 0 && time % 150 != 0) 
        con.print(1, 0, "Chassis Temp: %.1lf         ", chas.temp());
    if(time % 150 == 0)
        con.print(2, 0, cataLimit.get_value() ? "On     " : "Off     ");
}

#endif