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



void left_safe(){
    
    drive(600, 500);
    hangP.set(true);
    drive(-235);
    turn(-30, 800);
    hangP.set(false);
    turn_to(0);
    drive(775, 800);
    turn_to(45);
    intake.move(127);
    drive(375);
    drive(-200);
    turn(180);
    drive(-450, 500, 2);
    drive(250);

    turn_to(45);
    drive(-400);
    turn_to(0, 600);
    drive(-1200);
    turn_to(-47);
    blockerP.set(true);
    drive(-1675);   
}

void left_straight(){
    blockerP.set(true);
    delay(500);
    blockerP.set(false);
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
    drive(-2050, 2000);
    //turn(-40);
    //drive(-1000);
    turn_to(-65);
    drive(1500, 3000, 1, 25);
    //blockerP.set(true);
    //intakeP.set(true);
    // drive(-900);
    // turn(-35);
  //  intakeP.set(false);

}

void left_diagonal(){
    
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
    drive(-150);
    chas.spin_left(50);
    delay(1000);
    chas.stop();

}

void elims_left(){
    chas.spin(-127);
    delay(520);
    LwingsP.set(true);
    RwingsP.set(true);
    //drive(-800);
    chas.stop();
    delay(200);
    turn_to(80, 600);
    drive(-1500, 1000);
    LwingsP.set(false);
    RwingsP.set(false);
    turn_to(90);
    chas.spin(100);
    delay(400);
   // drive(1400, 2000, 1, 100);
    intake.move(127);
    chas.spin(60);
    delay(650);
    chas.stop();
    drive(-300, 800);
    intake.move(0);
    // turn_to(-90);
    // drive(-450,800);
    // drive(320, 1000);
    turn_to(0);
    drive(2600, 2000);
    turn_to(75);
    drive(-300, 700);
    turn_to(65);
    chas.spin(30);
    delay(1800);
    chas.stop();

    intake.move(0);
    //turn_to(90,800);
    //turn_to(135);

    

}

void rush_right_block(){ // trigger half cata -- editing this one 
   
    intake.move(-127);
    drive(200, 300);
    intake.move(0);
    drive(-1600, 950);

    turn_to(-34, 300);
    hangP.set(true);
    delay(100);
    drive(-1200, 900, 1, 75);
    
    turn_to(-90, 700, 1, 80);
    hangP.set(false);
    turn_to(100, 800);
    
    intake.move(55);
    drive(-200, 500);
    
    turn_to(-70);
    
    hangP.set(true);
    LwingsP.set(true);
    RwingsP.set(true);
    
    drive(-1050, 1000, 20);
    drive(200, 200);
    // turn_to(-70, 400);
    drive(-600, 400, 20);
    intake.move(-127);
    
    hangP.set(false);
    LwingsP.set(false);
    RwingsP.set(false);
    

    drive(600, 300);
    turn_to(0);
    drive(950, 1000);
    turn_to(53);
    drive(2350);
    
    turn_to(175);
    intake.move(127);
    delay(100);
    drive(-100, 300);
    turn_to(5);

    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1600, 900, 3);
    drive(500, 200);
    LwingsP.set(false);
    RwingsP.set(false);
    turn_to(-90);
    blockerP.set(true);
}

void rush_right_straight(){// trigger half cata 
    blockerP.set(true);
    delay(500);
    blockerP.set(false);
    intake.move(-127);
    drive(200, 300);
    intake.move(0);
    drive(-1600, 950);

    turn_to(-37, 300);
    hangP.set(true);
    delay(100);
    drive(-1000, 900, 1, 75);
    
    turn_to(-90, 700, 1, 80);
    hangP.set(false);
    turn_to(100, 800);
    
    intake.move(90);
    drive(-200, 500);
    
    turn_to(-80);
    
    hangP.set(true);
    
    drive(-1050, 1000, 20);
    drive(200, 200);
    // turn_to(-70, 400);
    drive(-600, 400, 20);
    intake.move(-127);
    
    hangP.set(false);

    drive(600, 300);
    turn_to(0);
    drive(950, 1000);
    turn_to(52);
    drive(2350);
    
    turn_to(175);
    intake.move(127);
    drive(-100, 300);
    turn_to(0);

    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1600, 900, 3);
    drive(500, 200);
    LwingsP.set(false);
    RwingsP.set(false);
    turn_to(90);

}
void right_safe_bar(){ // trigger half cata -- edting this one #1 safe
    blockerP.set(true);
    delay(500);
    hangP.set(true);
    blockerP.set(false);
    drive(-700, 1000);
    turn_to(-30, 500);
    drive(-400, 600);
    turn_to(-45, 500);
    
    hangP.set(false);
    drive(-1000, 1000, 2);
    drive(500);
    drive(-1000, 1000, 2);
    drive(650);
    turn_to(0);
    drive(1300, 900);
    turn_to(-135, 700);
    blockerP.set(true);
    drive(-1700);
    

}

void old_safe_right(){ // trigger half cata -- edting this one #2 safe
    hangP.set(true);
    drive(-685);
    turn_to(-60);
    drive(-100, 100);
    hangP.set(false);
    LwingsP.set(true);
    turn_to(-90);
    drive(-500);
    LwingsP.set(false);
    turn_to(90);
    intake.move(127);
    drive(100, 100);
    turn_to(-90);
    drive(-750, 1500, 5);
    intake.move(-127);
    
    drive(600);
    turn_to(0);
    drive(1000, 1000);
    turn_to(55);
    drive(400);
    turn_to(180);
    blockerP.set(true);
    drive(-1000);
    turn_to(225);
    drive(-1500, 3000, 1, 25);
    
}


void skills_V1(){
    //cata.tare_position();
    drive(100, 100);
    matchload_time(45); //45
    intake.move(127);
    
    drive(-50, 200);
    turn(32, 800); // make this absolute eh :shrug:
    drive(-900);
    turn_to(-2, 1000);
    drive(-3500);

    turn_to(-45);
    
    delay(100);
    LwingsP.set(true);
    drive(-1650);
    
    
    // chas.spin_left(-127);
    // delay(170);
    // chas.spin_left(0);
    LwingsP.set(false);
    turn_to(-90, 1000);
    drive_variable(-700, 10, 900);
    drive(600, 600);
    drive_variable(-600, 10, 950);
    drive(375, 300);
   
    

    turn_to(0, 500); // ahahaha
    drive(1000, 1000);//gerald was here
    turn_to(45, 600);
    drive(700, 600);
    turn_to(0, 600);
    drive(900, 1000);
     
    turn_to(-90, 900);
    drive(-1000, 1500);

    turn_to(0, 1000);
    

    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1600, 1000, 3);
    LwingsP.set(false);
    RwingsP.set(false);
    drive(1800);
    
    turn_to(-90, 1200);
    drive(-1400, 1500);
    turn_to(20, 1000);
    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1600, 1500, 3);
    turn_to(-10, 900);
    LwingsP.set(false);
    RwingsP.set(false);
    drive(1500, 1000);

    turn_to(0, 500);
    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1500, 1500, 5);
    drive(1300);
}

void skills_V2(){
    cata.tare_position();
    drive(100, 100);
    //matchload(47);
    
    drive(-50, 200);
    turn(32); // make this absolute eh :shrug:
    drive(-900);
    turn_to(0);
    drive(-3500);

    turn_to(-45);
    
    delay(100);
    LwingsP.set(true);
    drive(-1650);
    delay(100);
    
    // chas.spin_left(-127);
    // delay(170);
    // chas.spin_left(0);
    LwingsP.set(false);
    turn_to(-90);
    drive_variable(-900, 10, 1000);
    drive(280, 300);

    turn_to(0, 500); // ahahaha
    drive(1000, 1000);
    turn_to(45, 500);
    drive(600, 500);
    turn_to(0);
    drive(900);
     
    turn_to(-90, 500);
    

    drive(-900);

    turn_to(0, 500);
    
    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1600, 1000, 3);
    drive(1700);
    turn_to(-90, 500);
    
    drive(-1500);
    turn_to(0, 500);
    RwingsP.set(true);
    LwingsP.set(true);
    drive(-1600, 1000, 3);
    drive(1700);
    // turn_to(-90, 500);


    // turn_to(0, 500);
    // drive(-1500, 1500, 3);
    // drive(1500);

    // turn_to(30, 500);
    // drive(-1500, 1500, 3);
    // drive(1000);
}

void old_left(){
    drive(1100);
    turn_to(45);
    intake.move(127);
    drive(375);
    drive(-200);
    turn(180);
    drive(-450, 800, 2);
    drive(250);

    turn_to(45);
    drive(-400);
    turn_to(10);
    hangP.set(true);
    delay(200);
    drive(-715);
    turn(-20);
    
    drive(-600, 1500, 2);
    hangP.set(false);
    delay(100);
    turn_to(-47);
    blockerP.set(true);
    drive(-1650);   
}

void old_right(){
    
    
    hangP.set(true);
    drive(-685);
    chas.spin_left(-127);
    delay(205);
    chas.spin_left(0);
    hangP.set(false);
    LwingsP.set(true);
    turn(-25);
    LwingsP.set(false);
    drive(-950, 1500, 5);
    
    drive(500);
    turn_to(45);
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
    turn_to(135);

}


void blank(){}

void six_ball(){
    intake.move(-127);
    drive(200, 300);
    intake.move(0);
    drive(-1600, 950);
    
    turn_to(-37, 300);
    hangP.set(true);
    delay(100);
    drive(-1000, 900, 1, 75);
    
    turn_to(-90, 700, 1, 80);
    hangP.set(false);
    RwingsP.set(true);
    drive(-700, 300);
    
    RwingsP.set(false);
    turn_to(90);
    
    intake.move(127);
    drive(-100, 100);
    
    
    turn_to(-70);
    
    RwingsP.set(true);
    LwingsP.set(true);
    drive(-1200, 1500, 5);
    intake.move(-127);
    RwingsP.set(false);
    LwingsP.set(false);
    
    
    drive(600);
    turn_to(0);
    drive(1000, 1000);
    turn_to(52);
    
    drive(2220);
    
    turn_to(180);
    intake.move(100);
    delay(200);
    
    
    
    turn_to(-70);
    intake.move(-127);
    drive(600);
    delay(50);
    drive(-600, 500);
    turn_to(180, 300);
    intake.move(100);
    drive(-350, 300);
    turn_to(0);
    LwingsP.set(true);
    RwingsP.set(true);
    drive(-1500, 1000, 3);
    drive(500);
    turn_to(-90);
    blockerP.set(true);
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
    Auton("safe left", left_safe, "done"),
    Auton("block rush right", rush_right_block, "done"),
    Auton("straight rush right", rush_right_straight, "done"),
    Auton("bar safe right", right_safe_bar, "test on field"),
    Auton("elims rush", elims_left, "lardbots"),
    Auton("elims straight", left_straight, "done"),
    Auton("elims diagonal", left_diagonal, "done"),
    Auton("V1 skills", skills_V1, "DONT CHANGE NAME, run with triballs"),
    Auton("V2 skills", skills_V2, "DONT CHANGE NAME, run with triballs"),
    Auton("OLD left", old_left, "old"),
    Auton("OLD right", old_right, "old"),
    Auton("OLD SAFE right", old_safe_right, "old"),
    Auton("no auton", blank, "blank"),
    Auton("test", test, "test_function")
};

#endif