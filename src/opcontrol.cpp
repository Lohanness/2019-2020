#include "main.h"
#include "RobotBaseClass.cpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	//declare motors
	pros::Motor fRight(1);
	pros::Motor bRight(2);
	pros::Motor fLeft(3);
	pros::Motor bLeft(4);
	pros::ADIEncoder r(1,true);
	pros::ADIEncoder l(3,false);

/*
	Train rightTrain = Train(fRight,bRight,r); //create the right train
	Train leftTrain = Train(fLeft,bLeft,l);    //create the left train

	//declare the robot base
	RobotBase base = RobotBase(rightTrain,leftTrain);
	fRight.move_relative(10, 40);
	pros::delay(1000);
	base.forwardSpeed(30);
	pros::delay(500);
	base.stopTrains();
	pros::delay(500);
	base.stationaryTurn(90, 20);
*/
}
