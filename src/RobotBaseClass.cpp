#include "TrainClass.cpp"
#include "main.h"


class RobotBase {
  public:
  Train lt;
  Train rt;
  double ticksPerDeg;
  double controlSpeed = 1;
  int threshold = 10;
  int pastTick = 0;
  int currentTick = 0;
  int confirmedSame = 0;
  int lDesired;
  int rDesired;
  bool moving = false;
  bool logDrive;
  pros::ADIDigitalOut debug;
  RobotBase(Train rightTrain, Train leftTrain, double td, bool lD, int thr, pros::ADIDigitalOut db): lt(leftTrain),
  rt(rightTrain), ticksPerDeg(td), logDrive(lD), threshold(thr), debug(db) {};


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
    lt.rpm(Lspeed + Rspeed);
    rt.rpm(Lspeed - Rspeed);
  }


  void moveRPM(int sp) {
    lt.rpm(sp);
    rt.rpm(sp);
  }

  void forwardTile(double tiles, int speed) {
      lt.resetEncoders();
      rt.resetEncoders();
      moving = true;
      lt.moveTick(tiles,speed);
      rt.moveTick(tiles,speed);
      while(lt.checkMoving()==1 || rt.checkMoving()==1) {
        pros::delay(2);
      }
      moving = false;
      pros::lcd::set_text(4, "Not Moving");
  }

  void rotate(int direction, int degrees, int speed){
      lt.resetEncoders();
      rt.resetEncoders();
      lDesired = -1*direction*degrees*ticksPerDeg;
      rDesired = direction*degrees*ticksPerDeg;
      lt.rotateTick(lDesired, speed);
      rt.rotateTick(rDesired, speed);
      moving = true;
      debug.set_value(1);
      pros::delay(50);
      while(lt.checkMoving()==1 || rt.checkMoving()==1) {
        pros::delay(2);
      }
      moving = false;
      debug.set_value(0);
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

  void checkMoving() {
    currentTick = lt.getPos();
    if(currentTick == pastTick) {
      if(confirmedSame == 4) {
        moving = false;
        confirmedSame = 0;
      }
      confirmedSame+=1;
    } else {
      pastTick = currentTick;
      confirmedSame = 0;
    }
  }
};
