#ifndef _GLOBAL_
#define _GLOBAL_

#include "main.h"
#include <iostream>

using namespace pros;
using namespace std;

namespace glb
{
    #define P_RF 1
    #define P_RM 18
    #define P_RB 20
    #define P_LF 8
    #define P_LM 17
    #define P_LB 19
    #define P_INTAKE 10
    #define P_CATA 15
    #define P_CATASWITCH 'A'
    // temp ports
 
    Motor RF (P_RF, E_MOTOR_GEARSET_06);
    Motor RM (P_RM, E_MOTOR_GEARSET_06);
    Motor RB (P_RB, E_MOTOR_GEARSET_06);
    Motor LF (P_LF, E_MOTOR_GEARSET_06,1);
    Motor LM (P_LM, E_MOTOR_GEARSET_06,1);
    Motor LB (P_LB, E_MOTOR_GEARSET_06,1);
    Motor Intake (P_INTAKE, E_MOTOR_GEARSET_06,1);
    Motor Cata (P_CATA, E_MOTOR_GEARSET_36,1);
    ADIDigitalIn cataLimit(P_CATASWITCH);

    Controller con (E_CONTROLLER_MASTER);


}


#endif