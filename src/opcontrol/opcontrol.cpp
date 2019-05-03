#include "main.h"

void opcontrol() {

	//Identify which controller is the master constroller
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	//Identify all the motors
	pros::Motor fRight(1);
	pros::Motor bRight(2);
	pros::Motor fLeft(3);
	pros::Motor bLeft(4);

	while (true) {
		int leftY = master.get_analog(ANALOG_LEFT_Y);
		int leftX = master.get_analog(ANALOG_LEFT_X);

		fRight = leftY-leftX;
		bRight = leftY-leftX;
		fLeft = leftY+leftX;
		bLeft = leftY+leftX;

		pros::delay(10);
	}
}
