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
    turn_to(45);
    intake.move(127);
    drive(375);
    drive(-200);
    turn(180);
    drive(-450, 800, 2);
    drive(250);

    turn_to(45);
    drive(-250);
    chas.spin_left(-127);
    delay(200);
    chas.spin_left(0);
    intakeP.set(true);
    drive(-780);
    turn(-30);
    intakeP.set(false);
    drive(-600);
    turn_to(-28);
    drive(-1670);   
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
    drive(-685);
    chas.spin_left(-127);
    delay(205);
    chas.spin_left(0);
    intakeP.set(false);
    LwingsP.set(true);
    turn(-25);
    LwingsP.set(false);
    drive(-950, 1500, 5);
    
    drive(400);
    turn(92);
    drive(1000);
    turn(50);
    intake.move(-127);
    delay(150);
    
    // turn(180);
    drive(2220);
    
    turn(55);
    drive(300);
    
    turn(90);
    
    intake.move(127);
    
    delay(10);

    drive(600);
    turn(180);
    LwingsP.set(true);
    RwingsP.set(true);
    drive(-900, 1500, 3);
    
    drive(500, 1500);
   
    
    turn(90);

}

void right_bar(){
    intakeP.set(true);
    drive(-630);
    chas.spin_left(-127);
    delay(200);
    chas.spin_left(0);
    intakeP.set(false);
    LwingsP.set(true);
    turn(-25);
    LwingsP.set(false);
    drive(-950, 1500, 2);
    
    drive(750);
    chas.spin_left(127);
    delay(200);
    chas.spin_left(0);
    delay(100);
    turn(180);
    turn(-45);
    
    // turn(180);`  
    drive(-1630);
    chas.spin(0);

}


void skills(){
    
    drive(50);
    matchload(47);
    intake.move(127);

    drive(-50);
    turn(32);
    drive(-900);
    turn_to(0);
    drive(-3300, 400);

    turn_to(-45, 400);
    chas.spin_left(0);
    delay(100);
    LwingsP.set(true);
    drive(-1650, 400);
    delay(100);
    
    // chas.spin_left(-127);
    // delay(170);
    // chas.spin_left(0);
    LwingsP.set(false);
    turn_to(-90, 400);
    drive_variable(-700, 2, 400);
    drive(600, 200);
   
    drive_variable(-600, 3, 400);
    drive(280, 200);

    turn_to(0); // ahahaha
    drive(1000, 400);
    turn_to(45, 400);
    drive(700, 400);
    turn_to(0, 400);
    drive(825, 400);
     
    turn_to(-90, 400);
    drive(-1500, 400);

    turn_to(0, 200);
    

    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1400, 400, 3);
    drive(1500, 400);

    turn(-15, 400);
    drive(-1500, 1500, 3);
    drive(1500);

    turn(30);
    drive(-1500, 1500, 3);
    drive(1000);
}


void blank(){}


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

void test(){
    turn(180);
    delay(200);

    turn(-90);
    delay(200);

    turn(45);
    delay(200);

    turn(-22.5);
    delay(200);

    turn(12.25);
    delay(200);

    turn(-6);
    delay(200);

    turn(3);
    delay(200);

    turn(-1);
}

std::vector<Auton> autons
{
    Auton("test", test),
    Auton("elims straight", left_no_bar),
    Auton("elims diagonal", left_normal_align),
    Auton("left", defensive_left),
    Auton("right", offensive_right),
    Auton("pole right", right_bar),
    Auton("skills", skills),
    Auton("no auton", blank),
};

#endif