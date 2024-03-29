#ifndef __DRIVER__
#define __DRIVER__

#include "main.h"
#include "global.h"
#include "lib/auton_obj.h"
#include <iostream>
#include <cmath>

#define TURN_K 2.2

//using namespace pros;
using namespace glb;
//using namespace std;
bool intakeCooldown = false;
void drive()
{
    double left = abs(con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) > 10 ? con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) : 0;
    double right = abs(con.get_analog(E_CONTROLLER_ANALOG_RIGHT_X)) > 10 ? con.get_analog(E_CONTROLLER_ANALOG_RIGHT_X) : 0;
    
    //right = ((127.0 / pow(127, TURN_K)) * pow(abs(right), TURN_K) * (right/127));
    right /= 1.2275;

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
		intake.move(-127);
    else if(con.get_digital(E_CONTROLLER_DIGITAL_R2))
        intake.move(127);
    else 
        intake.move(0);
}


void cataConDelay(int time)
{
    static bool cataPressed;
    bool cataCheck = cataLimit.get_value();
    static int launchTime = 0;
    int distanceTri = dist.get();
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
    else if (cataPressed && cataCheck && distanceTri < 50)
    {
        cata.move(-127);
        intakeCooldown = true;
        launchTime = time;
    }
    else 
        cata.move(0);

    if (time > launchTime + 500)
        intakeCooldown = false;
    //if(time % 50 == 0 && time % 100 != 0 && time % 150 != 0)
     //   con.print(0, 0, false ? "MATCH LOAD     " : "FULL SPEED     ");
    
    //prevCataCheck = cataCheck;
    
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
void cataConHalf(int time)
{
    bool halfCata = true;
    static bool cataPressed = true;
    static bool matchload = false; 
    int pos = ((int) (abs(cata.get_position()))) % 1800;

    static int deadzone = 1600;
    bool cataCheck = (deadzone < pos && pos < 1690);
    bool buttonb = con.get_digital(pros::E_CONTROLLER_DIGITAL_L1);

    if (!matchload){
        if (true)
        { 
            if (halfCata && (deadzone < pos && pos < 1690) && !buttonb)
            {
                cata.move(0);
                deadzone = 1500;
                cataPressed = false;
            }
            else 
            {
                deadzone = 1600;
                cata.move(-127);
                cataPressed = true;
            }
        }
        if (buttonb)
            cataPressed = true;
        if (cataPressed)
            cata.move(-127);
        else 
        {
            cata.move(0);
            // cata.tare_position();
        }
    }
    else{
        cata.move(-127);
    }

    // if (con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
    //     halfCata = !halfCata;
    
    // if (halfCata && (time%200 == 0))
    // {
    //     //con.rumble(".");
    //     con.print(0,0, "%2f", pos);
    // }
    
    if (con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
        matchload = !matchload;
    }

}
Auton auton_selector(std::vector<Auton> autons)
{
    short int selected = 0;
    int timer = 0;

    while(true)
    {
        if(!glb::con.get_digital(pros::E_CONTROLLER_DIGITAL_A))
        {
            if(timer % 50 == 0 && timer % 100 != 0) 
                glb::con.print(0, 0, "Select: %s         ", autons.at(selected).get_name());
            if(timer % 100 == 0) 
                glb::con.print(1, 0, "%s            ", autons.at(selected).get_d());
            if(glb::con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT) && selected > 0)
                selected--;
            if(glb::con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT) && selected < autons.size()-1)
                selected++;
        }
        else
        {
            pros::delay(50);
            glb::con.clear();
            pros::delay(50);
            glb::con.print(0, 0, "selected:         "); 
            pros::delay(50);
            //glb::con.print(0, 0, "Selected           ");   
            glb::con.print(1, 0, "auton: %s         ", autons.at(selected).get_name());   
            pros::delay(50);
            //glb::con.print(0, 0, "Selected           ");   
            glb::con.print(2, 0, "%s             ", autons.at(selected).get_d()); 
            pros::delay(1500);
            glb::con.clear();
            return autons.at(selected);
        }

        pros::delay(1);
        timer++;
    }
}
void piston_cont()
{
    if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) blockerP.toggle();
    if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)){
        LwingsP.toggle();
        RwingsP.toggle();
    }
    if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)){
        hangP.toggle();
    } 
}

void print_info(int time, bool chassis_on)
{

    if(time % 50 == 0 && time % 100 != 0 && time % 150 != 0)
        con.print(0, 0, !chassis_on ? "CHASSIS OFF (right)            " : "%.1lf | %.1lf | %.1lf       ", chas.temp(), intake.get_temperature(), cata.get_temperature());
    if(time % 100 == 0 && time % 150 != 0) 
        con.print(1, 0, "%.2f : %.2f", imu.get_heading(), (cata.get_position()));
  //if(time % 150 == 0)
        //con.print(2, 0, "auton: %s         ", (*auton).get_name());
}

void print_info_auton(int time, double error, double speed)
{
    if(time % 50 == 0 && time%2000 != 0) 
        con.print(0, 0, "Error: %.2f : %.2f    ", error, speed);
    if(time % 100 == 0 && time % 150 != 0 && time%2000 != 0) 
        con.print(1, 0, "%.2f : %.2f          ", imu.get_heading(), chas.pos());
    if(time % 150 == 0 && time % 100 != 0 && time % 150 != 0 && time%2000 != 0) 
        con.print(2, 0, "%.2f | %.0f       ", error, time);
}

void print_name(int time, string name){
    if (time % 50 == 0 and time % 2000 != 0){
        con.print(0, 0, "%s", name);
    }
}

void print_skills(int time, int count){
    if (time % 2 == 0){
        con.print(2, 0, "%d", count);
    }
}

#endif