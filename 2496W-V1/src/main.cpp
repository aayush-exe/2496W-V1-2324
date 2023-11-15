#include "main.h"
#include "global.h"
#include "driver.h"
#include "auton.h"
#include "auton_func.h"
#include "pid.h"
#include "lib/auton_obj.h"
#include "lib/chassis.h"
#include "lib/piston.h"


#include <iostream>

using namespace pros;
using namespace std;
using namespace glb;
 
Auton *auton;
Auton temp;

void initialize() {
	lcd::initialize();
	con.clear();
	temp = auton_selector(autons);
	auton = &temp;
	
}

void autonomous() {(*auton).run();}

void opcontrol() 
{
	glb::con.clear();
	long long time = 0;
	bool chassis_on = true;
	chas.set_brake();
	chas.reset();
	

	if (temp.get_name() == "skills") pid::global_heading = 337;
	

	while(true)
	{
		if(chassis_on) drive();
		else chas.stop();

		intakeCon();
		cataConHalf(time);
		piston_cont();
		if ((*auton).get_name() != "SKILLS"){
			print_info(time, chassis_on);
		}
		
		if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) chassis_on = !chassis_on;
		if(con.get_digital(E_CONTROLLER_DIGITAL_UP) && chassis_on) autonomous();

		delay(2);
		time += 2;
	}
}
