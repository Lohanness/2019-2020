#include "main.h"
#include "globals.hpp"

void autonomous() {


  int toMove;
    if(autonColor == "red") {
      toMove = hRight;
    } else {
      toMove = hLeft;
    }



    if(skills) {
      base.sidewaysTile(toMove*-0.9,100);
      pros::delay(2000);

      base.forwardTile(0.1, 75);
      pros::delay(1000);

      claw.move(200);
      pros::delay(1000);
      claw.stop();

      base.forwardTile(-0.3,75);
      pros::delay(1000);

      dr4b.rise(2100,100);
      pros::delay(3000);

      base.forwardTile(0.5,40);
      pros::delay(2000);

      claw.resetPos(150);
      base.forwardTile(-0.7,40);
      pros::delay(2000);

      dr4b.rise(-2100,100);
      pros::delay(2000);

      base.rotateInertia(170,50);
      pros::delay(2000);

      base.sidewaysTile(toMove*0.3, 100);
      pros::delay(1000);

      base.forwardTile(-1.1, 40);
      pros::delay(2000);

      base.sidewaysTile(toMove*1.7, 120);
      pros::delay(2000);

      base.forwardTile(0.2, 50);
      pros::delay(500);

      claw.move(200);
      pros::delay(500);

      claw.move(0);
      dr4b.rise(550,100);
      pros::delay(500);

      base.forwardTile(0.8, 60);
      pros::delay(1500);

      base.sidewaysTile(toMove*-1.5,150);
      pros::delay(1500);

      base.forwardTile(0.5, 60);
      pros::delay(1000);

      base.sidewaysTile(toMove*-0.7, 150);
      pros::delay(1000);

      base.forwardTile(1.1, 60);
      pros::delay(1500);

      dr4b.rise(-570,100);
      pros::delay(500);

      claw.resetPos(200);
      pros::delay(1000);

      base.forwardTile(-1.4, 80);

    }


    if(autonSide=="protected") {

      if(autonType=="main") {

        base.sidewaysTile(toMove*2.77, 120);
        pros::delay(3500);

        base.forwardTile(0.2, 50);
        pros::delay(500);

        claw.move(200);
        pros::delay(500);
        claw.move(0);

        dr4b.rise(550,100);
        pros::delay(500);

        base.forwardTile(0.8, 60);
        pros::delay(1500);

        base.sidewaysTile(toMove*-1.5,150);
        pros::delay(1500);

        base.forwardTile(0.5, 60);
        pros::delay(1000);

        base.sidewaysTile(toMove*-1.4, 150);
        pros::delay(1000);

        base.sidewaysTile(toMove*0.1, 100);
        base.forwardTile(1.1, 60);
        pros::delay(1500);

        dr4b.rise(-570,100);
        pros::delay(500);

        claw.resetPos(200);
        pros::delay(1000);

        base.forwardTile(-1.4, 80);

      } else {

        base.sidewaysTile(toMove*-1, 150);
        pros::delay(4000);
        base.sidewaysTile(toMove*1, 150);
        pros::delay(11000);

      }

    } else {

      if(autonType=="main") {

        base.sidewaysTile(toMove*0.9,150);
        pros::delay(1500);

        base.forwardTile(0.15, 150);
        pros::delay(500);

        claw.move(200);
        pros::delay(500);
        claw.stop();

        base.forwardTile(-0.1,70);
        pros::delay(1000);

        dr4b.rise(2200,100);
        pros::delay(1250);

        base.forwardTile(0.3,70);
        base.sidewaysTile(toMove*0.2, 70);
        pros::delay(1000);

        claw.resetPos(200);
        base.sidewaysTile(toMove*-0.3, 70);
        base.forwardTile(-0.2, 70);
        pros::delay(1000);

        claw.move(40);
        dr4b.rise(-2200,100);
        pros::delay(100);

        claw.stop();
        pros::delay(900);

        base.rotateInertia(70,toMove*100);
        pros::delay(500);

        base.forwardTile(0.6, 100);
        pros::delay(1500);

        claw.move(200);
        pros::delay(500);

        dr4b.rise(700,100);
        base.forwardTile(-0.5, 100);
        base.sidewaysTile(toMove*1.35, 100);
        pros::delay(2500);

        claw.resetPos(200);
        dr4b.rise(-600,100);
        pros::delay(1000);

        claw.move(200);
        pros::delay(500);

        base.rotateInertia(175, toMove*150);
        pros::delay(1500);

        base.forwardTile(2, 100);
        pros::delay(2000);

        claw.resetPos(200);
      } else {

        base.sidewaysTile(toMove*1, 150);
        pros::delay(4000);
        base.sidewaysTile(toMove*-1, 150);
        pros::delay(11000);

      }


    }
}
