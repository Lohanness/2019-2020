#include "Train.cpp"
class RobotBase {
  public:
  Train *trains;
  RobotBase(Train rightTrain, Train leftTrain) {
    Train trains [2] = {rightTrain,leftTrain};
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

};
