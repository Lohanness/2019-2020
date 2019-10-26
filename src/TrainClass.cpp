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

  void moveTick(int distance, int velocity) {
      mot.move_relative(distance*onetile, velocity);
  }

  int getPos() {
    return mot.get_position();
  }

  void resetEncoders() {
    mot.tare_position();
  }
};
