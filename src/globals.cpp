#include "main.h"
#include "RobotBaseClass.cpp"
#include "Dispenser.cpp"
#include "DR4B.cpp"
#include "Claw.cpp"
std::string autonColor = "red";
std::string autonSquare = "right";

int rightT = -1;
int leftT= 1;
int th = 10;

pros::Motor frontLeft(1,true);
pros::Motor backLeft(2,true);
pros::Motor frontRight(3);
pros::Motor backRight(4);
pros::Motor hdr(5);
pros::Motor dr4b1(6);
pros::Motor dr4b2(7,true);
pros::Motor clawM(8);
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut led(1);

Train rightTrain = Train(1300,frontRight,backRight);
Train leftTrain = Train(1300,frontLeft,backLeft);
Train hDrive = Train(1300,hdr,hdr);
DR4B dr4b  = DR4B(540,dr4b1,dr4b2);
RobotBase base = RobotBase(rightTrain,leftTrain,hDrive,9.3,false,th,led);
Claw claw = Claw(clawM);
