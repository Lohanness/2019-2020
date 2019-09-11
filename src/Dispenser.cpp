#include "main.h"


class Dispenser {
public:
  pros::Motor one;
  pros::Motor two;
  int tick;
  Dispenser(int ticks, pros::Motor m1, pros::Motor m2): tick(ticks), one(m1), two(m2){}; //Train(Front motor, Back motor, ADIEncoder class, Encoder ticks per tile)

    //We must make an initializing function to obtain the motors in the train
    /*
    Train(int frontMotorPort,int backMotorPort, int ADIEncoderPort) {
      pros::Motor mots[] = {pros::Motor(frontMotorPort),pros::Motor(backMotorPort)}; //adds the motors to the train
      //enc = encoder;
    }
    */
  void rpm(int speedRPM) { //takes RPM at which to rotate the train
    one.move_velocity(speedRPM);
    two.move_velocity(speedRPM);
  }

  void stop() { //stop moving the train
    one.move_velocity(0);
    two.move_velocity(0);
  }

  void extendOut(int distance, int velocity) {
    //rotate the train a specified amount of degrees at a specified speed
      one.move_relative(distance*tick, velocity);
      two.move_relative(distance*tick, velocity);
  }
};
