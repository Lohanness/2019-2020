#include "TrainClass.cpp"
#include "main.h"

class RobotBase {
  public:
  Train lt;
  Train rt;
  int ticksPerDeg;
  double controlSpeed = 1;
  RobotBase(Train rightTrain, Train leftTrain,int ticksFor90Deg=150): lt(leftTrain), rt(rightTrain), ticksPerDeg(ticksFor90Deg/90) {};


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

  void stop() {
    lt.stop();
    rt.stop();
  }

  void cycleSpeedMode() {
    if(controlSpeed == 1) {
      controlSpeed = 0.5;
      return;
    }
    controlSpeed = 1;
  }
};
