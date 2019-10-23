#include "main.h"


class Dispenser {
public:
  pros::Motor one;
  pros::Motor two;
  int tick;
  int mode;
  bool deploying;
  int pastTick = 0;
  int currentTick = 0;
  int confirmedSame = 0;
  Dispenser(int ticks, pros::Motor m1, pros::Motor m2): tick(ticks), one(m1), two(m2){
    m1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    m2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  };

  void rpm(int speedRPM) {
    one.move_velocity(speedRPM);
    two.move_velocity(speedRPM);
  }

  void stop() {
    one.move_velocity(0);
    two.move_velocity(0);
  }

  void extend(int percent,int velocity) {
      deploying = true;
      one.move_relative((percent/100)*tick, velocity);
      two.move_relative((percent/100)*tick, velocity);
      while(one.get_position() < (percent/100)*tick) {
        pros::delay(2);
      }

  }

  void cycle(int velocity) {
    deploying = true;
    if(!(mode==2)) {
      one.move_relative(0.5*tick, velocity);
      two.move_relative(0.5*tick, velocity);
    } else {
      one.move_relative(tick,-1*velocity);
    }
    mode+=1;
  }

  int getPos() {
    return abs(int(one.get_position()));
  }

  void checkDeploying() {
    currentTick = getPos();
    if(currentTick == pastTick) {
      if(confirmedSame == 4) {
        deploying = false;
        confirmedSame = 0;
      }
      confirmedSame+=1;
    } else {
      pastTick = currentTick;
      confirmedSame = 0;
    }
  }
  void resetEncoders() {
    one.tare_position();
    two.tare_position();
  }
};
