#include "Train.cpp"
#include "main.h"


class RobotBase {
  public:
  Train *trains;
  int deg90;
  RobotBase(Train rightTrain, Train leftTrain,int rotates=200) {
    Train trains [2] = {rightTrain,leftTrain};
    deg90=rotates;
  }

  void forwardSpeed(int speed) {
    for(int i=0; i<sizeof(trains); i++) {
      trains[i].moveVelocity(speed);
    }
  }

  void backwardSpeed(int speed) {
    speed*=-1;
    for(int i=0; i<sizeof(trains); i++) {
      trains[i].moveVelocity(speed);
    }
  }

  void forwardTile(int tiles, int speed) {
    for(int i=0; i<sizeof(trains); i++) {
      trains[i].moveRelative(tiles,speed);
    }
  }

  void backwardTile(int tiles, int speed) {
    for(int i=0; i<sizeof(trains); i++) {
      trains[i].moveRelative(-tiles,speed);
    }
  }




  void stationaryTurn(int degrees, int speed) {
    int degturned = 0;
    while(degturned != degrees) {
      int rDegs = (trains[0].getEncoderVal()/deg90)*90;
      int lDegs = (trains[1].getEncoderVal()/deg90)*90;
      degturned = rDegs+lDegs;

      trains[0].moveVelocity(speed);
      trains[1].moveVelocity(speed);

    }
    trains[0].stop();
    trains[1].stop();
    trains[0].resetEncoders();
    trains[1].resetEncoders();
  }
};
