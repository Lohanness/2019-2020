#include "main.h"


class Dispenser {
public:
  pros::Motor one;
  pros::Motor two;
  int tick;
  int pastTick = 0;
  int currentTick = 0;
  int confirmedSame = 0;
  bool moving = false;

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
      moving = true;
      one.move_relative((percent/100)*tick, velocity);
      two.move_relative((percent/100)*tick, velocity);
      while(moving) {
          checkMoving();
          pros::delay(10);
          pros::lcd::set_text(1, "Moving");
      }
      pros::lcd::clear_line(1);
  }


  void checkMoving() {
    currentTick = one.get_position();
    if(currentTick == pastTick) {
      if(confirmedSame == 4) {
        moving = false;
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
