#include "main.h"
#include "RobotBaseClass.cpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void resetEncoders(pros::ADIEncoder enc) {
  enc.reset();
}

//declare motors
pros::Motor fRight(1);
pros::Motor bRight(2);
pros::Motor fLeft(3);
pros::Motor bLeft(4);
pros::ADIEncoder r(1,true);
pros::ADIEncoder l(3,false);

//Train rightTrain = Train(fRight,bRight,r); //create the right train
//Train leftTrain = Train(fLeft,bLeft,l);    //create the left train

//declare the robot base
//RobotBase base = RobotBase(rightTrain,leftTrain);


void autonomous() {
  fRight.move_velocity(-30);
  pros::delay(500);
  fRight.move_velocity(0);

/*
  pros::delay(1000);
  //pros::lcd::set_text(1, "b");
  pros::delay(500);
  base.forwardSpeed(30);
  //pros::lcd::set_text(1, "c");
	pros::delay(500);
  //pros::lcd::set_text(1, "d");
	base.stopTrains();
	pros::delay(500);
	base.stationaryTurn(90, 20);
*/
}
