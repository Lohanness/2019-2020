#include "main.h"
#include "globals.hpp"

void autonomous() {
  /*
    if(autonColor == "red") {
      if(autonSquare == "1") {
        base.forwardTile(1.1, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        claw.move(150);
        base.forwardTile(-.75, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.rotate(leftT, 90, 40);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.forwardTile(0.9, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        dispenser.extend(80, 150);
        while(dispenser.moving) {
          dispenser.checkMoving();
          pros::delay(2);
        }
        claw.stop();
        claw.resetPos(50);
          pros::delay(500);
      } else {
        base.forwardTile(0.25, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        claw.move(150);
        base.rotate(rightT, 90, 40);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.forwardTile(0.5, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.rotate(rightT, 45, 40);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        dispenser.extend(80,150);
        while(dispenser.moving) {
          dispenser.checkMoving();
          pros::delay(2);
        }
        claw.stop();
        claw.resetPos(50);
        pros::delay(500);
      }
    } else {
      if(autonSquare == "1") {
        base.forwardTile(1.1, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        claw.move(150);
        base.forwardTile(-.75, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.rotate(rightT, 90, 40);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.forwardTile(0.9, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        dispenser.extend(80, 150);
        while(dispenser.moving) {
          dispenser.checkMoving();
          pros::delay(2);
        }
        claw.stop();
        claw.resetPos(50);
          pros::delay(500);
      } else {
        base.forwardTile(0.25, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        claw.move(150);
        base.rotate(rightT, 90, 40);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.forwardTile(0.5, 50);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        base.rotate(rightT, 45, 40);
        while(base.moving) {
          base.checkMoving();
          pros::delay(2);
        }
        dispenser.extend(80,150);
        while(dispenser.moving) {
          dispenser.checkMoving();
          pros::delay(2);
        }
        claw.stop();
        claw.resetPos(50);
        pros::delay(500);
      }
    }
    */




  //  /*

  //  Works for some reason

    claw.move(70);
    pros::delay(1000);
    dr4b.rise(540,80);
    pros::delay(1000);
    base.forwardTile(1,80);
    pros::delay(1500);
    claw.resetPos(50);
    pros::delay(1000);
    dr4b.rise(-560,100);
    pros::delay(1000);
    claw.move(70);
    pros::delay(1000);
    dr4b.rise(270,80);
    pros::delay(1000);
    base.forwardTile(-1, 50);
    pros::delay(1000);
    base.rotate(leftT,85 ,80);
    pros::delay(1000);
    base.forwardTile(1,80);
    pros::delay(2000);
    base.moveRPM(50);
    pros::delay(500);
    base.stop();
    pros::delay(500);
    claw.resetPos(50);
    pros::delay(200);
    base.forwardTile(-1, 80);
    pros::delay(2000);
    pros::lcd::set_text(6, "AUTON COMPLETE");
//  */

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
}
