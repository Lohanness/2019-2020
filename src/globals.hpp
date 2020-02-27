#include "main.h"
#include "RobotBaseClass.cpp"
#include "Dispenser.cpp"
#include "DR4B.cpp"
#include "Claw.cpp"
using namespace pros;

#ifndef GLOBALS
#define GLOBALS

extern std::string autonColor, autonSide, autonType;
extern pros::Motor right, left, dr4b1, dr4b2, dispense, dispense2,clawM,hdr;
extern Train rightTrain, leftTrain,hDrive;
extern Dispenser dispenser;
extern pros::Imu ine;
extern DR4B dr4b;
extern Claw claw;
extern RobotBase base;
extern Inertia inertia;
extern int hLeft, hRight, th;
extern pros::Controller master;
#endif
