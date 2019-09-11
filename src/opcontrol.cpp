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

void opcontrol() {

  while(true) {
    int leftSpeed = master.get_analog(ANALOG_LEFT_Y);
    int rightSpeed = master.get_analog(ANALOG_RIGHT_Y);

    if(leftSpeed<-10) {
      leftTrain.rpm(-2*(leftSpeed*leftSpeed)/100);
    } else if(leftSpeed > 10) {
      leftTrain.rpm(2*(leftSpeed*leftSpeed)/100);
    } else {
      leftTrain.stop();
    }

    if(rightSpeed<-10) {
      rightTrain.rpm(-2*(rightSpeed*rightSpeed)/100);
    } else if(rightSpeed >10) {
      rightTrain.rpm(2*(rightSpeed*rightSpeed)/100);
    } else {
      rightTrain.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
      dispenser.rpm(-200);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
      dispenser.rpm(200);
    } else {
      dispenser.stop();
    }
  }


}
