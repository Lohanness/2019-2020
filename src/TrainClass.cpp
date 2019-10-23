#include "main.h"


class Train {
public:
  pros::Motor mot;
  int onetile;
  Train(int ot, pros::Motor m): onetile(ot),  mot(m) {
    //mot.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }; //Train(Front motor, Back motor, ADIEncoder class, Encoder ticks per tile)

  void rpm(int speedRPM) { //takes RPM at which to rotate the train
      mot.move_velocity(speedRPM);
  }

  void stop() { //stop moving the train
      mot.move_velocity(0);
  }

  void moveTick(int distance, int velocity) {
    //rotate the train a specified amount of degrees at a specified speed
      mot.move_relative(distance*onetile, velocity);
  }

  int getPos() {
    return mot.get_position();
  }

  void resetEncoders() {
    mot.tare_position();
  }
};
