#include "main.h"


class Train {
public:
  pros::Motor mot;
  int onetile;
  Train(int ot, pros::Motor m): onetile(ot),  mot(m) {}; //Train(Front motor, Back motor, ADIEncoder class, Encoder ticks per tile)
  
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


};
