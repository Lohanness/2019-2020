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
  int lDesired;
  int rDesired;
  bool moving = false;
  int currentRotation = 0;
  Inertia iner;
  RobotBase(Inertia inertiaSensor, Train rightTrain, Train leftTrain, Train center, double td):
  lt(leftTrain), rt(rightTrain), ticksPerDeg(td), hd(center), iner(inertiaSensor){};


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

  void setSpeedMode(double a, pros::Controller con) {
    controlSpeed = a;
    const char t1[] = "Full Speed   ";
    const char t2[] = "Half Speed   ";
    const char t3[] = "Quarter Speed";
    if(a==1) {
      con.set_text(0, 0, t1);
    } else if(a==0.5) {
      con.set_text(0, 0, t2);
    } else {
      con.set_text(0, 0, t3);
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
