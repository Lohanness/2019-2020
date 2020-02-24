#include "main.h"

class Train {
public:
  pros::Motor bm;
  pros::Motor fm;
  int onetile;
  Train(int ot, pros::Motor front, pros::Motor back): onetile(ot),  fm(front), bm(back) {};

  void rpm(int speedRPM) {
      fm.move_velocity(speedRPM);
      bm.move_velocity(speedRPM);
  }

  void stop() { //stop moving the train
      fm.move_velocity(0);
      bm.move_velocity(0);
  }

  void lock(bool yn) {
    if(yn) {
      bm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      fm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    } else {
      bm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      fm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
  }

  void moveTick(float distance, int velocity) {
      float toMove = distance*((float)onetile);
      fm.move_relative(toMove,velocity);
      bm.move_relative(toMove,velocity);
  }

  void rotateTick(int tick, int velocity) {
    fm.move_relative(tick,velocity);
    bm.move_relative(tick,velocity);
  }
  int getPos() {
    return (int)((fm.get_position()+bm.get_position())/2);
  }

  void resetEncoders() {
    fm.tare_position();
    bm.tare_position();
  }
  int checkMoving() {
    if(fm.is_stopped() && bm.is_stopped()) {
      return false;
    }
    return true;

  }
};
