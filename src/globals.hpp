#include "main.h"
#include "RobotBaseClass.cpp"
using namespace pros;

#ifndef GLOBALS
#define GLOBALS

extern std::string autonColor, autonSquare;
extern pros::Motor fRight, bRight, fLeft, bLeft;
extern pros::ADIEncoder right, left;
extern Train rightTrain, leftTrain;
extern RobotBase base;

#endif
