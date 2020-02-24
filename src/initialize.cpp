#include "main.h"
#include "globals.hpp"
bool i = false;
bool x = false;
int z = 0;

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
	autonSide="protected";
	if (!x){
		autonSide="non-protected";
	}
	pros::lcd::set_text(2, autonSide);
}

void rightbutton() {
	z=z+1;
	int max=5;
	if(z==max) {
		z=0;
	}
	if(z==0) {
		autonType="tower-stack";
		skills = false;
		pushAuton=false;
	} else if(z==1) {
		autonType="score-points";
		skills=false;
		pushAuton=false;
	} else if(z==2) {
		autonType="simple";
		skills=false;
		pushAuton=true;
	} else if(z==3) {
		autonType="push";
	} else {
		skills=true;
	}

	if(skills) {
		pros::lcd::set_text(3,"SKILLS AUTONOMOUS AUTONOMOUS");
	} else {
		pros::lcd::set_text(3, autonType);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, autonColor);
	pros::lcd::set_text(2, autonSide);
	pros::lcd::register_btn0_cb(centerbutton);
	pros::lcd::register_btn1_cb(leftbutton);
	pros::lcd::register_btn2_cb(rightbutton);
}

void disabled() {}

void competition_initialize() {}
