#include "main.h"
#include "globals.hpp"


bool i = false;
bool x = false;

void leftbutton() {
	i=!i;
	autonColor="blue";
	if (!i){
		autonColor="red";
	}
	pros::lcd::set_text(1, autonColor);
}

void centerbutton() {
	x=!x;
	autonSquare="1";
	if (!x){
		autonSquare="2";
	}
	pros::lcd::set_text(2, autonSquare);
}

void rightbutton() {
	autonomous();
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, autonColor);
	pros::lcd::set_text(2, autonSquare);
	pros::lcd::register_btn0_cb(centerbutton);
	pros::lcd::register_btn1_cb(leftbutton);
	pros::lcd::register_btn2_cb(rightbutton);
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
