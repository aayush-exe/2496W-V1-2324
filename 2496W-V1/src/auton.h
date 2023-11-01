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
    drive(250);
    turn(25);
    drive(-280);
    chas.spin_left(-127);
    delay(150);
    chas.spin_left(0);
    intakeP.set(true);
    drive(-900);
    turn(-35);
    intakeP.set(false);
    drive(-450);
    turn(-7);
    drive(-1665);   

}
void left_no_bar(){
    drive(1100);
    turn(45);
    intake.move(127);
    drive(390);
    drive(-400);
    turn(-180, 1500);
    intake.move(0);
    drive(-700, 1300);
    drive(200);
   // turn(25);
    turn_to(-6, 2000);
    drive(-2080, 2000);
    //turn(-40);
    //drive(-1000);
    turn(-60, 1000);
    drive(1500, 3000, 1, 25);
    //intakeP.set(true);
    // drive(-900);
    // turn(-35);
  //  intakeP.set(false);

}

void left_normal_align(){
    drive(1100);
    turn(45);
    intake.move(127);
    drive(390);
    drive(-400);
    turn(-180, 1500);
    intake.move(0);
    drive(-700, 1300);
    drive(200);
   // turn(25);
    turn_to(-6, 2000);
    drive(-1180, 2000);
    //turn(-40);
    //drive(-1000);
    turn(-90, 1000);
    drive(800, 1200, 1, 70);
    delay(300);
    drive(-120);
    chas.spin_left(50);
    delay(1000);
    chas.stop();


}


void offensive_right(){
    intakeP.set(true);
    drive(-630);
    chas.spin_left(-127);
    delay(200);
    chas.spin_left(0);
    intakeP.set(false);
    LwingsP.set(true);
    turn(-25);
    LwingsP.set(false);
    drive(-950);
    
    drive(300);
    chas.spin_left(127);
    delay(355);
    chas.spin(0);
    intake.move(-127);
    delay(150);
    
    // turn(180);
    drive(2700);
    delay(35);
    intake.move(0);
    turn(125);
    
    intake.move(127);
    delay(10);
    drive(1800);
    drive(-400);

}


void skills(){
    drive(30);
    //matchload(47);
    intake.move(127);

    drive(-50);
    turn(35);
    drive(-1000);
    turn(-25);
    drive(-3100);

    chas.spin_left(-127);
    delay(200);
    chas.spin_left(0);
    LwingsP.set(true);
    drive(-2000);
    delay(100);
    chas.spin_left(-127);
    delay(225);
    chas.spin_left(0);
    LwingsP.set(false);

    drive(-800, 1500, 3);
    drive(700);
    drive(-800, 1500, 3);
    drive(700);

    turn(110);
    drive(2250);   
    turn(-120);
    drive(-1500);
    turn(90);

    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1500, 1500, 3);
    drive(600);

    turn(-15);
    drive(-1500, 1500, 3);
    drive(500);

    turn(15);
    drive(-1200, 1500, 3);
    drive(1000);
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
    Auton("elims straight", left_no_bar),
    Auton("elims diagonal", left_normal_align),
    Auton("LEFT", defensive_left),
    Auton("RIGHT", offensive_right),
    Auton("SKILLS", skills),
    Auton("NO AUTON", blank),
    Auton("test", test)
};

#endif