#include "main.h"
#include "globals.hpp"


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

bool isout=false;

void dispenser() {
  if(isout) {
  dispense.move_relative(8500, 200);
  return;
  }
  dispense.move_relative(-8500,200);
}


void opcontrol() {

  while(true) {
    int leftSpeed = master.get_analog(ANALOG_LEFT_Y);
    int rightSpeed = master.get_analog(ANALOG_RIGHT_Y);

    if(leftSpeed<-10) {
      leftTrain.moveVelocity(-2*(leftSpeed*leftSpeed)/100);
    } else if(leftSpeed > 10) {
      leftTrain.moveVelocity(2*(leftSpeed*leftSpeed)/100);
    } else {
      leftTrain.stop();
    }

    if(rightSpeed<-10) {
      rightTrain.moveVelocity(-2*(rightSpeed*rightSpeed)/100);
    } else if(rightSpeed >10) {
      rightTrain.moveVelocity(2*(rightSpeed*rightSpeed)/100);
    } else {
      rightTrain.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
      isout = !isout;
      dispenser();
    }

    pros::lcd::set_text(5, "Right ticks: " + std::to_string(fRight.get_position()) + " , " + std::to_string(bRight.get_position()));
    pros::lcd::set_text(5, "Left ticks: " + std::to_string(fLeft.get_position()) + " , " + std::to_string(bLeft.get_position()));
  }

  while(true) {

    pros::delay(50);
    base.forwardTile(1,25);
    pros::delay(2500);
  }
}
