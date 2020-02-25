#include "TrainClass.cpp"
#include "InertiaSensor.cpp"
#include "main.h"


class RobotBase {
  public:
  Train lt;
  Train rt;
  Train hd;
  double ticksPerDeg;
  double controlSpeed = 1;
  int pastTick = 0;
  int currentTick = 0;
  int confirmedSame = 0;
  int lDesired;
  int rDesired;
  bool moving = false;
  int currentRotation = 0;
  Inertia iner;
  RobotBase(Inertia inertiaSensor, Train rightTrain, Train leftTrain, Train center, double td): lt(leftTrain),
  rt(rightTrain), ticksPerDeg(td), hd(center), iner(inertiaSensor){};


  void rpms(int Rspeed, int Lspeed) {/*
    if(logDrive) {
      if(Lspeed < -threshold) {
        lt.rpm(-2*(Lspeed*Lspeed)/100);
      } else if(Lspeed > threshold) {
        lt.rpm(2*(Lspeed*Lspeed)/100);
      } else {
        lt.stop();
      }

      if(Rspeed < -threshold) {
        rt.rpm(-2*(Rspeed*Rspeed)/100);
      } else if(Rspeed > threshold) {
        rt.rpm(2*(Rspeed*Rspeed)/100);
      } else {
        rt.stop();
      }

    } else {
      if(Rspeed > threshold || Rspeed < -threshold) {
        rt.rpm(Rspeed*2);
      } else {
        rt.stop();
      }
      if(Lspeed > threshold || Lspeed < -threshold) {
        lt.rpm(Lspeed*2);
      } else {
        lt.stop();
      }
    }
    */

  }


  void moveRPM(int sp) {
    lt.rpm(sp);
    rt.rpm(sp);
  }

  void forwardTile(float tiles, int speed) {
      lt.resetEncoders();
      rt.resetEncoders();
      lt.moveTick(tiles,speed);
      rt.moveTick(tiles,speed);
  }

  void sidewaysTile(float tiles, int speed) {
    hd.resetEncoders();
    hd.moveTick(tiles,speed);
  }

  void rotate(int direction, int degrees, int speed){
      lt.resetEncoders();
      rt.resetEncoders();
      lDesired = -1*direction*degrees*ticksPerDeg;
      rDesired = direction*degrees*ticksPerDeg;
      lt.rotateTick(lDesired, speed);
      rt.rotateTick(rDesired, speed);
      moving = true;
      pros::delay(50);
      while(lt.checkMoving()==1 || rt.checkMoving()==1) {
        pros::delay(2);
      }
      moving = false;
  }

  void rotateInertia(int degrees, int speed) {
    int rSpeed = speed*-1;
    int lSpeed = speed;

    int toTurn = currentRotation + abs(degrees);
    rt.rpm(rSpeed);
    lt.rpm(lSpeed);
    int currentRotation = abs(iner.getRotation());
    while(currentRotation < toTurn) {
      currentRotation = abs(iner.getRotation());
      if(currentRotation/toTurn > 0.5) {
        rt.rpm(rSpeed/3);
        lt.rpm(lSpeed/3);
      }
    }
    pros::lcd::set_text(3, "Finished Rotating");
    rt.stop();
    lt.stop();
  }
  void stop() {
    lt.stop();
    rt.stop();
  }

  void cycleSpeedMode() {
    if(controlSpeed == 1) {
      controlSpeed = 0.25;
    } else {
      controlSpeed = 1;
    }
  }

  void moveTicks(int ticks, int speed) {
    lt.resetEncoders();
    rt.resetEncoders();
    lt.rotateTick(ticks, speed);
    rt.rotateTick(ticks, speed);
  }

  void hDriveTick(int ticks, int speed) {
    hd.resetEncoders();
    hd.rotateTick(ticks, speed);
  }

  bool checkMoving() {
    if(rt.checkMoving() || rt.checkMoving() || hd.checkMoving()) {
      return true;
    }
    return false;
  }
};
