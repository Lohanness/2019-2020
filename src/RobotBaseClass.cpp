#include "TrainClass.cpp"
#include "main.h"

class RobotBase {
  public:
  Train lt;
  Train rt;
  int ticksPerDeg;
  RobotBase(Train rightTrain, Train leftTrain,int ticksFor90Deg=150): lt(leftTrain), rt(rightTrain), ticksPerDeg(ticksFor90Deg/90) {};

/*
  int abs(int a) {
    if(a<0) {
      a*=-1;
    }
    return a;
  }
*/

  void forwardSpeed(int speed) {
     lt.rpm(speed);
     rt.rpm(speed);
  }

  void backwardSpeed(int speed) {
    speed*=-1;
    lt.rpm(speed);
    rt.rpm(speed);
  }

  void forwardTile(int tiles, int speed) {
      lt.moveTick(tiles,speed);
      rt.moveTick(tiles, speed);
  }

  void backwardTile(int tiles, int speed) {
      lt.moveTick(-tiles,speed);
      rt.moveTick(-tiles, speed);
  }

  void stop() {
    lt.stop();
    rt.stop();
  }

};
