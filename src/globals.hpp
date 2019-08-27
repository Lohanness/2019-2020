#include "main.h"
#include "RobotBaseClass.cpp"
using namespace pros;

#ifndef GLOBALS
#define GLOBALS

extern std::string autonColor, autonSquare;
extern pros::Motor fRight, bRight, fLeft, bLeft, dispense;
extern pros::ADIEncoder right, left;
extern Train rightTrain, leftTrain;
extern RobotBase base;
extern pros::Controller master;

#endif
