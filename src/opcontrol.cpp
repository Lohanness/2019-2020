#include "main.h"
#include "globals.hpp"

bool holding = false;
bool driving = false;
void opcontrol() {

  while(true) {
    int leftSpeed = master.get_analog(ANALOG_LEFT_Y);
    int rightSpeed = master.get_analog(ANALOG_LEFT_X);

    base.rpms(rightSpeed,leftSpeed);
    if(!(rightSpeed > th || rightSpeed < -th) && !(leftSpeed > th || leftSpeed < -th)) {
      rightTrain.stop();
      leftTrain.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
      base.rpms(50,50);
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
      dispenser.rpm(100);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
      dispenser.rpm(-100);
    } else {
      dispenser.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
      dr4b.rpm(100);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
      dr4b.rpm(-100);
    } else {
      dr4b.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_A)) {
      claw.move(100);
      claw.closing = true;
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {
      claw.move(-100);
      claw.closing = false;
    } else if(!claw.closing) {
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


    pros::delay(5);
  }
}
