#include "main.h"
#include "globals.hpp"

bool holding = false;
bool driving = false;
void opcontrol() {

  while(true) {
    /*

    DRIVE CONTROLS

    */
    bool bls = false;
    bool brs = false;
    bool hls = false;
    int baseSpeed= -2*master.get_analog(ANALOG_LEFT_Y);
    int hSpeed = 2*master.get_analog(ANALOG_LEFT_X);

    int turning = (-2*master.get_analog(ANALOG_RIGHT_X))/3;

    if(baseSpeed > th || baseSpeed < -th) {
      bls = true;
    }

    if(hSpeed > th || hSpeed < -th) {
      hls = true;
    } else {
      hDrive.stop();
    }

    if((turning > th || turning < -th) && !bls) {
      brs = true;
    }

    if(bls && !brs) {
      base.moveRPM(-baseSpeed);
    } else if(brs && !bls) {
      rightTrain.rpm(turning);
      leftTrain.rpm(-turning);
    } else {
      rightTrain.stop();
      leftTrain.stop();
    }
    if(hls) {
      rightTrain.lock(true);
      leftTrain.lock(true);
      hDrive.rpm(hSpeed);
    } else {
      rightTrain.lock(false);
      leftTrain.lock(false);
    }

    /*

    DR4B CONTROLS

    */
    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
      dr4b.rpm(100);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
      dr4b.rpm(-100);
    } else {
      dr4b.stop();
    }

    /*

    CLAW CONTROLS

    */
    if(master.get_digital(E_CONTROLLER_DIGITAL_A)) {
      claw.move(200);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {
      claw.move(-200);
    } else {
      claw.stop();
    }

    /*

    CHANGE BASE SPEED

    */
    if(master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
      base.setSpeedMode(1, master);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_LEFT)) {
      base.setSpeedMode(0.5, master);
    } else {
      base.setSpeedMode(0.25, master);
    }


    pros::delay(5);
  }
}
