#include "main.h"


class DR4B {
public:
  pros::Motor rightdr4b;
  pros::Motor leftdr4b;
  int tick;
  bool raising;
  int pastTick = 0;
  int currentTick = 0;
  int confirmedSame = 0;
  DR4B(int ticks, pros::Motor m1, pros::Motor m2): tick(ticks), rightdr4b(m1), leftdr4b(m2){}; //Train(Front motor, Back motor, ADIEncoder class, Encoder ticks per tile)

    //We must make an initializing function to obtain the motors in the train
    /*
    Train(int frontMotorPort,int backMotorPort, int ADIEncoderPort) {
      pros::Motor mots[] = {pros::Motor(frontMotorPort),pros::Motor(backMotorPort)}; //adds the motors to the train
      //enc = encoder;
    }
    */
  void rpm(int speedRPM) { //takes RPM at which to rotate the train
    rightdr4b.move_velocity(speedRPM);
    leftdr4b.move_velocity(speedRPM);
  }

  void stop() { //stop moving the train
    rightdr4b.move_velocity(0);
    leftdr4b.move_velocity(0);
  }

  void Rise(int percent, int velocity) {
      rightdr4b.move_relative((percent/100)*tick, velocity);
      leftdr4b.move_relative((percent/100)*tick, velocity);
  }

  int getPos() {
    return abs(int(rightdr4b.get_position()));
  }

  void checkRaising() {
    currentTick = getPos();
    if(currentTick == pastTick) {
      if(confirmedSame == 4) {
        raising = false;
        confirmedSame = 0;
      }
      confirmedSame+=1;
    } else {
      pastTick = currentTick;
      confirmedSame = 0;
    }
  }
};
