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

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, autonColor);
	pros::lcd::set_text(2, autonSquare);
	pros::lcd::register_btn0_cb(centerbutton);
	pros::lcd::register_btn1_cb(leftbutton);
}

void disabled() {}

void competition_initialize() {}
