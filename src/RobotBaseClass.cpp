#include "TrainClass.cpp"
#include "main.h"


class RobotBase {
  public:
  Train lt;
  Train rt;
  double ticksPerDeg;
  double controlSpeed = 1;
  int threshold = 10;
  bool moving = false;
  bool logDrive;
  RobotBase(Train rightTrain, Train leftTrain, double td, bool lD, int thr): lt(leftTrain), rt(rightTrain), ticksPerDeg(td), logDrive(lD), threshold(thr) {};


  void rpms(int Rspeed, int Lspeed) {
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
  }



  void forwardTile(double tiles, int speed) {
      lt.resetEncoders();
      rt.resetEncoders();
      lt.moveTick(tiles,speed*controlSpeed);
      rt.moveTick(tiles,speed*controlSpeed);
      while(lt.getPos() < tiles) {
        pros::delay(2);
        pros::lcd::set_text(1, "Moving");
      }
      pros::lcd::clear_line(1);
  }

  void backwardTile(double tiles, int speed) {
      lt.moveTick(-tiles,speed*controlSpeed);
      rt.moveTick(-tiles,speed*controlSpeed);
  }

  void rotate(int direction,int degrees, int speed){
      int rOriginal = rt.getPos();
      int lOriginal = lt.getPos();
      int lDesired = -1*direction*degrees*ticksPerDeg;
      int rDesired = direction*degrees*ticksPerDeg;
      lt.moveTick(lDesired, speed);
      rt.moveTick(rDesired, speed);
      moving = true;
      while(lt.getPos() != lDesired + lOriginal  && rt.getPos() < rDesired + rOriginal) {
        pros::delay(2);
      }
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
};
