#ifndef __PID__
#define __PID__

#include "main.h"
#include "global.h"
#include "auton_func.h"
#include "lib/chassis.h"

#include "pros/misc.h"
#include "pros/rtos.h"
#include <iostream>
#include <fstream>
#include <list>
#include <cmath>

using namespace pros;
using namespace std;
using namespace glb;

#define DRIVE_KP_H 0.2

#define DRIVE_KI_H 0
#define DRIVE_KD_H 0
#define IMU_K_H 0

namespace pid
{
    double start_head = 0; 
    //For Yousef: finish abs turn
    //For Brandon: improve
    double end_head = 0;
    double global_heading = 0;

    void drive(double target_dist, int timeout=3000, double mult=1.0, double max_speed=127, int exit_time=50, double dou_kp = DRIVE_KP_H, double dou_ki = DRIVE_KI_H,double dou_kd = DRIVE_KD_H,double dou_imuk = IMU_K_H)
    {
        #define DRIVE_KP ((17.6647 * (pow(target_dist, -0.975028))) + 0.139685) //0.14
        //500: 0.1777
        //1000: 0.1685
        //2000: 0.1429

        #define DRIVE_KI 0//0.002 //0.00085
        #define DRIVE_KD 0 //5


        #define IMU_K 0.001

        if (fabs(end_head) - fabs(imu.get_heading()) > 1) {
            start_head += end_head-imu.get_heading();
        }

        int starting = 180;
        // start_head -= starting;
        imu.set_heading(starting);

        //Set Variables
        double target = target_dist + chas.pos();
        double error = target - chas.pos();
        double prev_error;
        double integral = 0;
        double kintegral = 0;
        double derivative = 0;
        double init_heading = imu.get_heading();
        double heading_error = 0;
        double error_range_time = 0;
        bool start_positive = target_dist >= 0 ? true : false;

        bool exit = false;

        int time = 0;

        while (time < timeout)
        {
            prev_error = error;
            
            //P
            error = target - chas.pos();
            //I
            if(fabs(error)<60) {
                integral += error;
            }
            //D
            derivative = (error - prev_error) * 1000;

            //Correct sides, ensure heading stays same as beginning
            heading_error = init_heading - imu.get_heading();

            //PID
            double speed = mult * (error * DRIVE_KP + integral * DRIVE_KI + derivative * DRIVE_KD);

            //Heading correction
            kintegral += heading_error;

            double correction = (kintegral * IMU_K);

            //Cap speed and correction sum to max
            if (fabs(speed) + fabs(correction) > max_speed) 
            {
                double multiplier = max_speed/(fabs(speed) + fabs(correction));
                speed *= multiplier;
                correction *= multiplier;
            }

            //Exit Loop
            // if (fabs(error) < 4)
            // {
            //     if(!exit)
            //         exit = true;
            //     else
            //         error_range_time++;
            //     if (exit_time <= error_range_time)
            //         break;
            // }

            //Keep sides moving the same distances
            // chas.spin_left(speed + correction * speed / 127.0);
            // chas.spin_right(speed - correction * speed / 127.0);
            chas.spin(speed);

            //Logging
            print_info_auton(time, error);
            
            //Prevent infinite loops
            pros::delay(1);
            time++;
        }
        chas.stop();
        double diff = imu.get_heading() - starting;
        if (fabs(diff)>2) {
            start_head+=diff;
        }
        
        end_head = imu.get_heading();

        global_heading += imu.get_heading() - starting;
    }

    double turn_f(double error)
    {
        return error / fabs(error) * (25 * log(0.25 * (fabs(error) + 4)) + 5);
    }

    void turn(double target_deg, int timeout=3000, double multi=1.0, double max_speed=127, int exit_time=100)
    {  
        bool absturn = false; // THIS IS TEMPORARY lol cus I made it a separate func. remove it later maybe
        #define TURN_KP .7 //.7
        #define TURN_KI 10
        #define TURN_KD 0.3 //.45

        int starting;

        if (fabs(end_head) - fabs(imu.get_heading()) > 1) {
            start_head += end_head-imu.get_heading();
        }


        if (absturn) {
            if (target_deg>150) {
                starting=30;
            }
            else if (target_deg<-150) {
                starting=330;
            }
            else {
                starting=180;
            }
            target_deg -= start_head;
        }

        else {
            if (target_deg > 150)
                starting = 30;
            else if (target_deg < -150)
                starting = 330;
            else
                starting = 180;
        }
        
        imu.set_heading(starting);
        

        double target = target_deg + imu.get_heading();
        double error = target_deg;
        double prev_error;
        double integral = 0;
        double derivative = 0;
        double error_range_time;

        bool exit = false;

        int time = 0;
        while (time<timeout)
        {
            prev_error = error;
            error = target - imu.get_heading();
            if(fabs(error) < 1.5)
                integral += error / 1000;
            derivative = (error - prev_error) * 1000;

            double speed = turn_f(error) * TURN_KP + integral * TURN_KI + derivative * TURN_KD;

            if (fabs(speed) > max_speed) 
            {
                double multiplier = max_speed/fabs(speed);
                speed *= multiplier;
            }

            if (fabs(error) < 0.15)
            {
                if(!exit)
                    exit = true;
                else
                    error_range_time++;
                if (exit_time <= error_range_time)
                    break;
            }

            chas.spin_left(speed * multi);
            chas.spin_right(-speed * multi);

            print_info_auton(time, error);

            pros::delay(1);
            time++;
        }
        chas.stop();

        double diff = imu.get_heading() - starting;
        
        if (absturn) {
            start_head = imu.get_heading() - 180;
        }

        else {
            start_head+=diff;
        }
        
        end_head = imu.get_heading();

        global_heading += imu.get_heading() - starting;
    }

    void turn_to(double degree_to, int timeout=3000, double multi=1.0, double max_speed=127, int exit_time=100)
    {
        double degree = degree_to - global_heading;
        degree = (degree > 180) ? -(360 - degree) : ((degree < -180) ? (360 + degree) : (degree)); // optimize the turn direction
        turn(degree, timeout, multi, max_speed, exit_time);
    }
}


#endif