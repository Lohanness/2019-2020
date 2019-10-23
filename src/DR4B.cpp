#include "main.h"

class DR4B {
public:
  pros::Motor rightdr4b;
  pros::Motor leftdr4b;
  int tick;
  bool raising;
  int pastTick = 0;
  int currentTick = 0;
  int confirmedSame = 0;
  DR4B(int ticks, pros::Motor m1, pros::Motor m2): tick(ticks), rightdr4b(m1), leftdr4b(m2){
    rightdr4b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    leftdr4b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  };

  void rpm(int speedRPM) {
    rightdr4b.move_velocity(speedRPM);
    leftdr4b.move_velocity(speedRPM);
  }



  void stop() {
    rightdr4b.move_velocity(0);
    leftdr4b.move_velocity(0);

  }

  void rise(int percent, int velocity) {
      rightdr4b.move_relative((percent/100)*tick, velocity);
      leftdr4b.move_relative((percent/100)*tick, velocity);
  }

  int getPos() {
    return abs(int(rightdr4b.get_position()));
  }

  void checkRaising() {
    currentTick = getPos();
    if(currentTick == pastTick) {
      if(confirmedSame == 4) {
        raising = false;
        confirmedSame = 0;
      }
      confirmedSame+=1;
    } else {
      pastTick = currentTick;
      confirmedSame = 0;
    }
  }
};
