#include "main.h"


class Train {
public:
  pros::Motor front; //declaration of motor array to store motors in the train
  pros::Motor back;
  pros::ADIEncoder enc;
  int onetile;
  Train(pros::Motor m1,pros::Motor m2, pros::ADIEncoder encode, int t): front(m1), back(m2), enc(encode), onetile(t) {}; //Train(Front motor, Back motor, ADIEncoder class, Encoder ticks per tile)

    //We must make an initializing function to obtain the motors in the train
    /*
    Train(int frontMotorPort,int backMotorPort, int ADIEncoderPort) {
      pros::Motor mots[] = {pros::Motor(frontMotorPort),pros::Motor(backMotorPort)}; //adds the motors to the train
      //enc = encoder;
    }
    */
  void moveVelocity(int speedRPM) { //takes RPM at which to rotate the train
      front.move_velocity(speedRPM); //set the motors speed to the RPM
      back.move_velocity(speedRPM);
  }

  void stop() { //stop moving the train
      front.move_velocity(0); //stop the motor
      back.move_velocity(0);
  }

  void moveRelative(int distance, int velocity) { //rotate the train a specified amount of degrees at a specified speed
      front.move_relative(distance*onetile, velocity);
      back.move_relative(distance*onetile, velocity);
  }

  void resetEncoder() {
      enc.reset();
  }

  int getEncoderVal() {
      return enc.get_value();
  }

};
