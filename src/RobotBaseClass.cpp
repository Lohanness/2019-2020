#include "TrainClass.cpp"
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

  void stopTrains() {
    trains[0].stop();
    trains[1].stop();
  }

  void printEncoders() {
    //pros::lcd::set_text(1,"Right Encoder: "  + std::to_string(trains[0].getEncoderVal()));
    //pros::lcd::set_text(2,"Left Encoder: "  + std::to_string(trains[1].getEncoderVal()));
  }
  void resetEncoders() {
    trains[0].resetEncoders();
    trains[1].resetEncoders();
  }
  void stationaryTurn(int degrees, int speed) {
    int degturned = 0;
    printEncoders();
    while(degturned != degrees) {
      resetEncoders();
      //int rDegs = (trains[0].getEncoderVal()/deg90)*90;
      //int lDegs = (trains[1].getEncoderVal()/deg90)*90;
    //  degturned = rDegs+lDegs;

      trains[0].moveVelocity(speed);
      trains[1].moveVelocity(speed);

    }
    stopTrains();
    resetEncoders();
  }



  void movingCurve(int degrees, int distance, int speed) {
    /*
    If turning left:
    Train1 = right train
    Train2 = left train

    If turning right:
    Train1 = left train
    Train2 = right train

    T2RPM = (T2 Rotates * T1 Speed)/T1 Rotates

    */

    Train t1 = trains[0];
    Train t2 = trains[1];
    if(degrees <0) {
      t1=trains[1];
      t2=trains[0];
    }


  }

  void rotateAndMove(int degrees, int distance, int speed) {
    stationaryTurn(degrees, speed);
    forwardTile(distance,speed);
  }
};
