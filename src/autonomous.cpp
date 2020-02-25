#include "main.h"
#include "globals.hpp"

void autonomous() {

  inertia.initialize();


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

      return;
    }


    if(autonSide=="protected") {

      if(autonType=="tower-stack") {

        /*if(trayBotExists) {


            CODE TOWERS 1 CUBE OF OPPOSITE COLOR OF ITS SIDE, SCORES 4 STACK


        } else {


            CODE TOWERS 1 CUBE OF MATCHING COLOR OF ITS SIDE, SCORES 4 STACK


        }*/

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

      } else if(autonType=="score-points") {

        /*
          CODE PUSHES IN PRELOAD, SCORES 4 STACK ON TOP
        */

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

      } else if(autonType=="simple") {

        /*
          CODE TOWERS 1 PURPLE CUBE, SCORES PRELOAD
        */

      } else {

        /*
          PUSHES IN PRELOAD
       */

        base.sidewaysTile(toMove*-1, 150);
        pros::delay(4000);
        base.sidewaysTile(toMove*1, 150);
        pros::delay(11000);

      }

    } else {

      if(autonType=="tower-stack") {

        base.sidewaysTile(toMove*0.9,150);
        pros::delay(1500);
        base.forwardTile(0.15, 150);
        pros::delay(500);
        claw.move(200);
        pros::delay(500);
        claw.stop();
        base.forwardTile(-0.1,70);
        //base.sidewaysTile(toMove*0.5, 200);
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

        //base.rotate(toMove, 90, 50);
        base.rotateInertia(70,toMove*100);
        pros::delay(500);
        /*
        base.sidewaysTile(toMove*-2.4, 200);
        base.forwardTile(-0.4, 200);
        pros::delay(500);
        */
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
        /*
        base.forwardTile(0.4, 150);
        pros::delay(500);
        base.rotateInertia(90,toMove*100);
        pros::delay(1000);
        base.forwardTile(0.7,200);

        rightTrain.rpm(200);
        pros::delay(1000);
        base.forwardTile(2, 200);
        claw.resetPos(200);
        pros::delay(2000);
        base.forwardTile(-0.1, 200);
        claw.resetPos(200);
        pros::delay(500);
        base.forwardTile(-0.3, 200);
        */
        pros::delay(1500);
        base.forwardTile(2, 100);
        pros::delay(2000);
        claw.resetPos(200);
        return;
      } else if(autonType=="score-points") {

        /*
          MAKES AND SCORES 4 STACK
        */

      } else {

        /*
          PUSHES IN PRELOAD
        */

        base.sidewaysTile(toMove*1, 150);
        pros::delay(4000);
        base.sidewaysTile(toMove*-1, 150);
        pros::delay(11000);

      }


    }

  //

  //  Works for some reason

/*
pros::lcd::set_text(4, "RUNNING AUTONOMOUS");
base.forwardTile(0.8, 80);
pros::delay(2000);
base.sidewaysTile(0.5, 90);
pros::delay(300);
base.moveTicks(-1500, 75);
pros::delay(3000);
base.hDriveTick(290, 80);
pros::lcd::set_text(4, "FINISHED AUTONOMOUS");


*/



/*

      WORKING AUTONOMOUS JUST FIX CLAW


    base.moveRPM(50);
    pros::delay(100);
    base.stop();
    pros::delay(200);
    claw.moveTicks(720,200);
    pros::delay(1500);
    dr4b.rise(600,80);
    pros::delay(1000);
    base.forwardTile(1,80);
    pros::delay(1500);
    claw.resetPos(200);
    pros::delay(2000);
    dr4b.rise(-620,100);
    pros::delay(1000);
    claw.moveTicks(720,200);
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
    claw.resetPos(200);
    pros::delay(2000);
    base.forwardTile(-1, 100);
    pros::delay(2000);
    pros::lcd::set_text(6, "AUTON COMPLETE");
    */

/*

    THEORETICAL 4 POINTS

*/
if(pushAuton) {
  base.sidewaysTile(toMove*-1, 150);
  pros::delay(4000);
  base.sidewaysTile(toMove*1, 150);
  pros::delay(11000);
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

} else {
  base.sidewaysTile(toMove*0.77, 100);
  pros::delay(2000);
}

base.sidewaysTile(toMove*0.3, 100);
pros::delay(1000);
if(skills) {
base.forwardTile(-1.1, 40);
pros::delay(2000);
}
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
