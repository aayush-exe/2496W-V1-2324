#ifndef _GLOBAL_
#define _GLOBAL_

#include "main.h"

#include "pros/misc.h"
#include "pros/rtos.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iostream>

using namespace pros;
using namespace std;

namespace glb{
    #define P_RF 1
    #define P_RM 2
    #define P_RB 3
    #define P_LF 4
    #define P_LM 5
    #define P_LB 6
    // temp ports
 
    Motor RF (P_RF, E_MOTOR_GEARSET_06);
    Motor RM (P_RM, E_MOTOR_GEARSET_06);
    Motor RB (P_RB, E_MOTOR_GEARSET_06);
    Motor LF (P_LF, E_MOTOR_GEARSET_06,1);
    Motor LM (P_LM, E_MOTOR_GEARSET_06,1);
    Motor LB (P_LB, E_MOTOR_GEARSET_06,1);

    Controller con (E_CONTROLLER_MASTER);


}


#endif