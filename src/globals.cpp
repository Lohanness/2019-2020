#include "main.h"
#include "RobotBaseClass.cpp"
std::string autonColor = "red";
std::string autonSquare = "right";

pros::Motor fRight(1, true);
pros::Motor bRight(2,true);
pros::Motor fLeft(3);
pros::Motor bLeft(4);

pros::Motor dispense(5);
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::ADIEncoder right(1, true);
pros::ADIEncoder left(3, false);

Train rightTrain = Train(fRight,bRight,right,1300); //create the right train
Train leftTrain = Train(fLeft,bLeft,left,1300);    //create the left train

RobotBase base = RobotBase(rightTrain,leftTrain,150);
