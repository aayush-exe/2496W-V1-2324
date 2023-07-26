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
    int power = con.get_analog(ANALOG_LEFT_Y); // left joystick y axis is power
    int valForTurn = con.get_analog(ANALOG_RIGHT_X); // right joystick x axis controls turn
    // double turn = (abs(valForTurn) * valForTurn / 75);

    //sensitivity commands
    // double turn = (3000*valForTurn + 0.2*pow(valForTurn, 3)); 
    // turn /= 5000;
    
    double turn = valForTurn; 
    turn /= 1.45;
    // turn = turn / 1.25
    
    int left = power + turn; // implement turning
    int right = power - turn; 

    RF.move(right);
    RM.move(right); //hii
    RB.move(right); // hi
    LF.move(left);
    LM.move(left);
    LB.move(left);	

    delay(10);
}



#endif