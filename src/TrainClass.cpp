#include "main.h"

class Train {
public:
  pros::Motor mot;
  int onetile;
  Train(int ot, pros::Motor m): onetile(ot),  mot(m) {};

  void rpm(int speedRPM) {
      mot.move_velocity(speedRPM);
  }

  void stop() { //stop moving the train
      mot.move_velocity(0);
  }

  void moveTick(double distance, int velocity) {
      double toMove = distance*onetile;
      mot.move_relative(toMove, velocity);
  }

  void rotateTick(int tick, int velocity) {
      mot.move_relative(tick, velocity);
  }
  int getPos() {
    return mot.get_position();
  }

  void resetEncoders() {
    mot.tare_position();
  }
  int checkMoving() {
    return mot.is_stopped();
  }
};
