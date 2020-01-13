#include "main.h"
#include "globals.hpp"

void autonomous() {
  int toTurn;
    if(autonColor == "red") {
      toTurn = leftT;
    } else {
      toTurn = rightT;
    }





  //

  //  Works for some reason


    base.moveRPM(50);
    pros::delay(100);
    base.stop();
    pros::delay(200);
    claw.move(70);
    pros::delay(1000);
    dr4b.rise(600,80);
    pros::delay(1000);
    base.forwardTile(1,80);
    pros::delay(1500);
    claw.resetPos(50);
    pros::delay(1000);
    dr4b.rise(-620,100);
    pros::delay(1000);
    claw.move(70);
    pros::delay(1000);
    dr4b.rise(540,80);
    pros::delay(1000);
    base.forwardTile(-1, 50);
    pros::delay(1000);
    base.rotate(toTurn,85 ,80);
    pros::delay(1000);
    base.forwardTile(1,80);
    pros::delay(2000);
    base.moveRPM(60);
    pros::delay(500);
    base.stop();
    pros::delay(500);
    dr4b.rise(-300,80);
    pros::delay(1000);
    claw.resetPos(50);
    pros::delay(500);
    base.forwardTile(-1, 100);
    pros::delay(2000);
    pros::lcd::set_text(6, "AUTON COMPLETE");
//

/*
claw.move(75);
delay(500);
dr4b.rise(20,80);
while(dr4b.moving) {
  pros::delay(2);
}
base.forwardTile(0.25,80);
while(base.moving) {
  pros::delay(2);
}
claw.resetPos(50);
while(claw.moving) {
  pros::delay(2);
}
dr4b.rise(-19,60);
while(dr4b.moving) {
  pros::delay(2);
}
claw.move(75);
while(claw.moving) {
  pros::delay(2);
}
dr4b.rise(10,80);
while(dr4b.moving) {
  pros::delay(2);
}
base.rotate(leftT,90,75);
while(base.moving) {
  pros::delay(2);
}
base.forwardTile(0.5,80);
while(base.moving) {
  pros::delay(2);
}
dr4b.rise(-9,60);
while(dr4b.moving) {
  pros::delay(2);
}
claw.resetPos(50);
while(claw.moving) {
  pros::delay(2);
}


*/

/*
base.forwardTile(-1, 80);
pros::delay(2000);
base.forwardTile(1, 80);
pros::delay(2000);
*/
}
