#include "main.h"
#include "globals.hpp"
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




void autonomous() {

    if(autonColor == "red") {
      if(autonSquare == "right") {

          //right square red side


      } else {

          //left square red side

      }
    } else {
      if(autonSquare == "right") {

          //right square blue side

      } else {

          //left square blue side

      }
    }
    base.forwardTile(1, 50);
}
