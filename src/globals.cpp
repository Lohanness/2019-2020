#include "main.h"
#include "RobotBaseClass.cpp"
#include "Dispenser.cpp"
#include "DR4B.cpp"

std::string autonColor = "red";
std::string autonSquare = "right";

pros::Motor right(1);
pros::Motor left(2,true);
pros::Motor dr4b1(3);
pros::Motor dr4b2(4,true);
pros::Motor dispense(5);
pros::Motor dispense2(6,true);
pros::Motor claw(7);
pros::Motor knocker(8);
pros::Controller master(pros::E_CONTROLLER_MASTER);

Train rightTrain = Train(1300,right); //create the right train
Train leftTrain = Train(1300,left);    //create the left train
Dispenser dispenser = Dispenser(8000,dispense, dispense2);
DR4B lift = DR4B(500,dr4b1,dr4b2);
RobotBase base = RobotBase(rightTrain,leftTrain,150);
