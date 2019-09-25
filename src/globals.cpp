#include "main.h"
#include "RobotBaseClass.cpp"
#include "Dispenser.cpp"
#include "DR4B.cpp"
#include "Claw.cpp"
std::string autonColor = "red";
std::string autonSquare = "right";

pros::Motor right(1,true);          //right drive
pros::Motor left(2);      //left drive
pros::Motor dr4b1(3);          //right side dr4b
pros::Motor dr4b2(4);     //left side dr4b
pros::Motor dispense(5);       //left side dispenser
pros::Motor dispense2(6,true); //right side dispenser
pros::Motor clawM(7);
pros::Motor knocker(8);
pros::Controller master(pros::E_CONTROLLER_MASTER);

Train rightTrain = Train(1300,right); //create the right train
Train leftTrain = Train(1300,left);    //create the left train
Dispenser dispenser = Dispenser(8000,dispense, dispense2);
DR4B dr4b  = DR4B(117,dr4b1,dr4b2);
RobotBase base = RobotBase(rightTrain,leftTrain,150);
Claw claw = Claw(35,clawM);
