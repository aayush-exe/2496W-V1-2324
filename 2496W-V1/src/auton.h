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

void defensive_left(){

    drive(1100);
    turn(45);
    intake.move(127);
    drive(350);
    drive(-200);
    turn(-25);
    drive(300);
    turn(25);
    drive(-350);
    chas.spin_left(-127);
    delay(150);
    chas.spin_left(0);
    intakeP.set(true);
    drive(-900);
    turn(-35);
    intakeP.set(false);
    drive(-450);
    turn(-15);
    drive(-1665);
    
    
    

}


void offensive_right(){
    intakeP.set(true);
    drive(-600);
    chas.spin_left(-127);
    delay(230);
    chas.spin_left(0);
    turn(-30);
    drive(-900);
    drive(300);
    chas.spin_left(127);
    delay(375);
    chas.spin_right(0);
    delay(50);
    drive(2400);
    turn(-75);
    RwingsP.set(true);
    LwingsP.set(true);
    turn(25);
    drive(-900);
    
}


void skills(){
    matchload(47);
}


void blank(){}


void test()
{
    drive(1230);
    delay(10);
    turn_to(180);
    delay(10);
    drive(1230);
    //turn(180);
}


void test_mode()
{
    long long timer = 0;
    double temp_kp = DRIVE_KP_H;
    double temp_ki = DRIVE_KI_H;
    double temp_kd = DRIVE_KD_H;
    double temp_imuk = IMU_K_H;
    int selected = 0;
    string items[4] ={"KP","KI","KD","IMU_K"};

    while(true)
    {
        if(timer % 50 == 0) 
            glb::con.print(0, 0, "Constant tuning: %s         ", items[selected]);

        if(glb::con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT) && selected > 0)
            selected--;

        if(glb::con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT) && selected < 3)
            selected++;

        if(glb::con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP))
            selected++;
        if(glb::con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))
            selected++;

        if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_A))
        {
            drive(1000, 10000, 1.0, 127, 50, temp_kp, temp_ki, temp_kd, temp_imuk);
        }
        pros::delay(1);
        timer++;
    }
}

std::vector<Auton> autons
{
    Auton("LEFT", defensive_left),
    Auton("RIGHT", offensive_right),
    Auton("SKILLS", skills),
    Auton("NO AUTON", blank),
    Auton("test", test)
};

#endif