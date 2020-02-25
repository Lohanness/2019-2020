#include "main.h"

class DR4B {
public:
  pros::Motor rightdr4b;
  pros::Motor leftdr4b;
  bool moving = false;
  DR4B( pros::Motor m1, pros::Motor m2): rightdr4b(m1), leftdr4b(m2){
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


  bool checkMoving() {
    if(rightdr4b.is_stopped() && leftdr4b.is_stopped()) {
      return false;
    }
    return true;
  }

  void resetEncoders() {
    rightdr4b.tare_position();
    leftdr4b.tare_position();
  }
};
