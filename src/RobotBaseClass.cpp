#include "TrainClass.cpp"
#include "main.h"


class RobotBase {
  public:
  Train lt;
  Train rt;
  double ticksPerDeg;
  double controlSpeed = 1;
  RobotBase(Train rightTrain, Train leftTrain, double td): lt(leftTrain), rt(rightTrain), ticksPerDeg(td) {};


  void forwardSpeed(int speed) {
     lt.rpm(speed*controlSpeed);
     rt.rpm(speed*controlSpeed);
  }

  void backwardSpeed(int speed) {
    speed*=-1;
    lt.rpm(speed*controlSpeed);
    rt.rpm(speed*controlSpeed);
  }

  void forwardTile(int tiles, int speed) {
      lt.moveTick(tiles,speed*controlSpeed);
      rt.moveTick(tiles,speed*controlSpeed);
  }

  void backwardTile(int tiles, int speed) {
      lt.moveTick(-tiles,speed*controlSpeed);
      rt.moveTick(-tiles,speed*controlSpeed);
  }

  void rotate(int direction,int degrees, int speed){
      lt.moveTick(-1*direction*degrees*ticksPerDeg, speed);
      rt.moveTick(direction*degrees*ticksPerDeg, speed);

  }

  void stop() {
    lt.stop();
    rt.stop();
  }


  void cycleSpeedMode() {
    if(controlSpeed == 1) {
      controlSpeed = 0.5;
    } else {
      controlSpeed = 1;
    }
  }
};
