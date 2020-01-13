#include "main.h"

class Train {
public:
  pros::Motor bm;
  pros::Motor fm;
  int onetile;
  Train(int ot, pros::Motor front, pros::Motor back): onetile(ot),  fm(front), bm(back) {};

  void rpm(int speedRPM) {
      fm.move_velocity(speedRPM);
      fm.move_velocity(speedRPM);
  }

  void stop() { //stop moving the train
      fm.move_velocity(0);
      fm.move_velocity(0);
  }

  void moveTick(double distance, int velocity) {
      double toMove = distance*onetile;
      fm.move_relative(toMove,velocity);
      fm.move_relative(toMove,velocity);
  }

  void rotateTick(int tick, int velocity) {
    fm.move_relative(tick,velocity);
    fm.move_relative(tick,velocity);
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
      return true;
    }
    return false;

  }
};
