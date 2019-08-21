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

std::string ac = autonColor;
std::string as = autonSquare;

pros::Motor fRight(1, true);
pros::Motor bRight(2, true);
pros::Motor fLeft(3);
pros::Motor bLeft(4);

pros::ADIEncoder right(1, true);
pros::ADIEncoder left(1, false);
Train rightTrain = Train(fRight,bRight,right,300); //create the right train
Train leftTrain = Train(fLeft,bLeft,left,300);    //create the left train

RobotBase base = RobotBase(rightTrain,leftTrain,150);


void autonomous() {

    if(ac == "red") {
      if(as == "right") {

          //right square red side

      } else {

          //left square red side

      }
    } else {
      if(as == "right") {

          //right square blue side

      } else {

          //left square blue side

      }
    }

    /*
    base.forwardSpeed(30);
    pros::delay(500);
    base.stop();
    pros::delay(500);
    base.stationaryTurn(1000, 35);
    */
}
