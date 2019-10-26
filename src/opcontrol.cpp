#include "main.h"
#include "globals.hpp"

bool holding = false;

void opcontrol() {

  while(true) {
    int leftSpeed = master.get_analog(ANALOG_LEFT_Y);
    int rightSpeed = master.get_analog(ANALOG_RIGHT_Y);

    base.rpms(rightSpeed,leftSpeed);
    if(!(rightSpeed > th || rightSpeed < -th)) {
      rightTrain.stop();
    }
    if(!(leftSpeed > th || leftSpeed < -th)) {
      leftTrain.stop();
    }


    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
      dispenser.rpm(150);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
      dispenser.rpm(-150);
    } else {
      dispenser.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
      dr4b.rpm(200);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
      dr4b.rpm(-100);
    } else {
      dr4b.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_A)) {
      claw.move(50);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {
      claw.move(-50);
    } else {
      claw.stop();
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_RIGHT) && !holding) {
      base.cycleSpeedMode();
      holding = true;
    }
    if(!master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
      holding = false;
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
      dr4b1.move_velocity(50);
    } else if(!(master.get_digital(E_CONTROLLER_DIGITAL_L2) ||
     master.get_digital(E_CONTROLLER_DIGITAL_L1))) {
      dr4b1.move_velocity(0);
    }

    pros::delay(5);
  }
}
