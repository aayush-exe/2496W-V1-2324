#ifndef __GLOBAL__
#define __GLOBAL__

#include "main.h"
#include "lib/chassis.h"
#include "lib/piston.h"

using namespace pros;
using namespace std;

namespace glb
{
    // ports
    #define P_IMU 2
    #define P_RF 13
    #define P_RM 18
    #define P_RB 20
    #define P_LF 8
    #define P_LM 17
    #define P_LB 11
    #define P_INTAKE 10
    #define P_CATA 15
    #define P_DISTANCE 3
    #define P_CATASWITCH 'A'
    #define P_INTAKEP 'C'
    #define P_RWINGSP 'G'
    #define P_LWINGSP 'H'
    #define P_SPIKE 'D'
   
    //objects
    Chassis chas({P_LF, P_LM, P_LB}, {P_RF, P_RM, P_RB}, pros::E_MOTOR_GEARSET_06, false);
    Motor intake(P_INTAKE, E_MOTOR_GEARSET_06);
    Motor cata (P_CATA, E_MOTOR_GEARSET_36,1);

    Piston LwingsP(P_LWINGSP);
    Piston RwingsP(P_RWINGSP);
    Piston intakeP(P_INTAKEP);
    Piston spikeP(P_SPIKE);

    Distance dist(P_DISTANCE);
    Imu imu(P_IMU);
    ADIDigitalIn cataLimit(P_CATASWITCH);

    Controller con(E_CONTROLLER_MASTER);

}
#endif