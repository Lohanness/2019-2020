#include "main.h"
#include "globals.hpp"

void leftbutton() {
	if(autonColor=="blue") {
		autonColor="red";
	} else {
		autonColor="red";
	}
	pros::lcd::set_text(1, autonColor);
}

void centerbutton() {
	if(autonSide=="protected") {
		autonSide="non-protected";
	} else {
		autonSide = "protected";
	}
	pros::lcd::set_text(2, autonSide);
}

void rightbutton() {


	if(autonType=="main") {
		autonType="push";
	} else if(autonType=="push") {
		skills=true;
		autonType="skills";
	} else {
		autonType="main";
		skills=false;
	}

		pros::lcd::set_text(3, autonType);
}

void initialize() {
	inertia.initialize();
	pros::lcd::initialize();
	pros::lcd::set_text(1, autonColor);
	pros::lcd::set_text(2, autonSide);
	pros::lcd::register_btn0_cb(centerbutton);
	pros::lcd::register_btn1_cb(leftbutton);
	pros::lcd::register_btn2_cb(rightbutton);
}

void disabled() {}

void competition_initialize() {}
