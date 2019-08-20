#include "main.h"
int i = 0;
int x = 0;
string auton;
string square;
void leftbutton() {
	if (i == 1){
		auton="red";
		i = 0;
	}
	else{
		auton = "blue";
		i = 1;
	}
	pros::lcd::set_text(1, auton);
}

void centerbutton() {
	if (x == 1){
		square = "left";
		x = 0;
	}
	else{
		square = "right";
		x = 1;
	}
	pros::lcd::set_text(2, square);
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::register_btn0_cb(centerbutton);
	pros::lcd::register_btn1_cb(leftbutton);
	//autonomous();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
