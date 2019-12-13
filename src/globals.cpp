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

pros::Motor right(1,true);
pros::Motor left(2);
pros::Motor dr4b1(3);
pros::Motor dr4b2(4,true);
pros::Motor dispense(5);
pros::Motor dispense2(6,true);
pros::Motor clawM(7);
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut led(1);

Train rightTrain = Train(1300,right);
Train leftTrain = Train(1300,left);
Dispenser dispenser = Dispenser(1400,dispense, dispense2);
DR4B dr4b  = DR4B(540,dr4b1,dr4b2);
RobotBase base = RobotBase(rightTrain,leftTrain,9.3,false,th,led);
Claw claw = Claw(clawM);
