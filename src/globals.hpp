#include "main.h"
#include "RobotBaseClass.cpp"
#include "Dispenser.cpp"
#include "DR4B.cpp"
#include "Claw.cpp"
using namespace pros;

#ifndef GLOBALS
#define GLOBALS

extern std::string autonColor, autonSquare;
extern pros::Motor right, left, dr4b1, dr4b2, dispense, dispense2,clawM,knocker;
extern Train rightTrain, leftTrain;
extern Dispenser dispenser;
extern DR4B dr4b;
extern Claw claw;
extern RobotBase base;
extern int rightT, leftT, threshold;
extern pros::Controller master;

#endif
