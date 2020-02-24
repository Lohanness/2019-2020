#include "main.h"
#include "globals.hpp"

bool holding = false;
bool driving = false;
void opcontrol() {

  while(true) {
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
    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
      dispenser.rpm(100);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
      dispenser.rpm(-100);
    } else {
      dispenser.stop();
    }
*/
    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
      dr4b.rpm(100);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
      dr4b.rpm(-100);
    } else {
      dr4b.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_A)) {
      claw.move(200);
      claw.closing = true;
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {
      claw.move(-200);
      claw.closing = false;
    } else /*if(!claw.closing)*/ {
      claw.stop();
    }/*else {
      claw.stop();
    }*/

    if(master.get_digital(E_CONTROLLER_DIGITAL_RIGHT) && !holding) {
      base.cycleSpeedMode();
      holding = true;
    }
    if(!master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
      holding = false;
    }

    int zAxis = inertia.getRotation();
    std::string toPrintInertia = std::to_string(zAxis);
  //  pros::lcd::set_text(1, toPrintInertia);

    pros::delay(5);
  }
}
