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
     lt.moveVelocity(speed);
     rt.moveVelocity(speed);
  }

  void backwardSpeed(int speed) {
    speed*=-1;
    lt.moveVelocity(speed);
    rt.moveVelocity(speed);
  }

  void forwardTile(int tiles, int speed) {
      lt.moveRelative(tiles,speed);
      rt.moveRelative(tiles, speed);
  }

  void backwardTile(int tiles, int speed) {
      lt.moveRelative(-tiles,speed);
      rt.moveRelative(-tiles, speed);
  }

  void stop() {
    lt.stop();
    rt.stop();
  }

  void printEncoders() {
    pros::lcd::set_text(1,"Right Encoder: "  + std::to_string(lt.getEncoderVal()));
    pros::lcd::set_text(2,"Left Encoder: "  + std::to_string(rt.getEncoderVal()));
  }
  void resetEncoders() {
    lt.resetEncoder();
    rt.resetEncoder();
  }


  void stationaryTurn(int degrees, int speed) {
    resetEncoders();
    int ticksWanted = degrees*ticksPerDeg;
    bool reached = false;
    int ltEnc = abs(lt.getEncoderVal());
    int rtEnc = abs(rt.getEncoderVal());

    while(!reached) {

      printEncoders();
      ltEnc = abs(lt.getEncoderVal());
      rtEnc = abs(rt.getEncoderVal());

      if(ltEnc+rtEnc >= ticksWanted) {
        reached = true;
        continue;
      }

      lt.moveVelocity(speed);
      rt.moveVelocity(-speed);

      pros::delay(10);

    }
    stop();
    resetEncoders();
  }




  void rotateAndMove(int degrees, int distance, int speed) {
    stationaryTurn(degrees, speed);
    forwardTile(distance,speed);
  }



};
