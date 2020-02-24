#include "main.h"
#include "RobotBaseClass.cpp"
#include "Dispenser.cpp"
#include "DR4B.cpp"
#include "Claw.cpp"

std::string autonColor = "blue";
std::string autonSide = "non-protected";
std::string autonType = "tower-stack";
bool trayBotExists = false;
bool skills = false;
bool pushAuton = false;


int hRight = 1;
int hLeft= -1;
int th = 20;


pros::Motor frontLeft(20);
pros::Motor backLeft(19);
pros::Motor frontRight(18,true);
pros::Motor backRight(17,true);
pros::Motor hdr(16);
pros::Motor dr4b1(13);
pros::Motor dr4b2(1,true);
pros::Motor clawM(14,true);
pros::Imu ine(15);
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut led(1);

Train rightTrain = Train(1300,frontRight,backRight);
Train leftTrain = Train(1300,frontLeft,backLeft);
Train hDrive = Train(2600,hdr,hdr);
DR4B dr4b  = DR4B(540,dr4b1,dr4b2);
Inertia inertia = Inertia(ine);
RobotBase base = RobotBase(inertia, rightTrain,leftTrain,hDrive,9.3,false,th,led);

Claw claw = Claw(clawM);
