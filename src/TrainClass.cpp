
#include "main.h"


class Train {
public:
  pros::Motor *mots; //declaration of motor array to store motors in the train
  //pros::ADIEncoder enc = pros::ADIEncoder(1,true);
    //We must make an initializing function to obtain the motors in the train
    Train(int frontMotorPort,int backMotorPort, int ADIEncoderPort) {
      pros::Motor mots[] = {pros::Motor(frontMotorPort),pros::Motor(backMotorPort)}; //adds the motors to the train
      //enc = encoder;
    }
  void moveVelocity(int speedRPM) { //takes RPM at which to rotate the train
    for(int i=0; i<sizeof(mots); i++) { //foreach motor in the train

      mots[i].move_velocity(speedRPM); //set the motors speed to the RPM

    }
  }

  void stop() { //stop moving the train
    for(int i=0; i<sizeof(mots); i++) { //foreach motor in the train
      mots[i].move_velocity(0); //stop the motor
    }
  }

  void moveRelative(int distance, int velocity) { //rotate the train a specified amount of degrees at a specified speed
    for(int i=0; i<sizeof(mots); i++) { //foreach motor in the train

      mots[i].move_relative(distance, velocity);
    }
  }


  void resetEncoders() {
    //  enc.reset();
  }
/*
  int getEncoderVal() {
    return  enc.get_value();
  }
  */
};
