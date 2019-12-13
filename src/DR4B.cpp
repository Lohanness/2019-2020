#include "main.h"

class DR4B {
public:
  pros::Motor rightdr4b;
  pros::Motor leftdr4b;
  int tick;
  int pastTick = 0;
  int currentTick = 0;
  int confirmedSame = 0;
  bool moving = false;
  DR4B(int ticks, pros::Motor m1, pros::Motor m2): tick(ticks), rightdr4b(m1), leftdr4b(m2){
    rightdr4b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    leftdr4b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    rightdr4b.set_gearing(pros::E_MOTOR_GEARSET_18);
    leftdr4b.set_gearing(pros::E_MOTOR_GEARSET_18);
  };

  void rpm(int speedRPM) {
    rightdr4b.move_velocity(speedRPM);
    leftdr4b.move_velocity(speedRPM);
  }



  void stop() {
    rightdr4b.move_velocity(0);
    leftdr4b.move_velocity(0);

  }

  void rise(int ticks, int velocity) {
      rightdr4b.move_relative(ticks, velocity);
      leftdr4b.move_relative(ticks, velocity);
      moving = true;
      while(rightdr4b.is_stopped() ==1 || leftdr4b.is_stopped() == 1) {
          pros::delay(2);
      }
      moving = false;
      pros::lcd::clear_line(1);
  }


  void checkMoving() {
    currentTick = rightdr4b.get_position();
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
    rightdr4b.tare_position();
    leftdr4b.tare_position();
  }
};
