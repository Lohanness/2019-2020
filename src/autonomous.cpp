#include "main.h"
#include "globals.hpp"

void autonomous() {
    if(autonColor == "red") {
      if(autonSquare == "1") {
        base.forwardTile(1.1, 50);
        claw.move(150);
        base.forwardTile(-.75, 50);
        base.rotate(leftT, 90, 40);
        base.forwardTile(0.9, 50);
        dispenser.extend(80, 150);
        claw.resetPos(50);
      } else {
        base.forwardTile(0.25, 50);
        claw.move(150);
        base.rotate(rightT, 90, 40);
        base.forwardTile(0.5, 50);
        base.rotate(rightT, 45, 40);
        dispenser.extend(80,150);
        claw.resetPos(50);
      }
    } else {
      if(autonSquare == "1") {
        base.forwardTile(1.1, 50);
        claw.move(150);
        base.forwardTile(-.75, 50);
        base.rotate(rightT, 90, 40);
        base.forwardTile(0.9, 50);
        dispenser.extend(80, 150);
        claw.resetPos(50);
      } else {
        base.forwardTile(0.25, 50);
        claw.move(150);
        base.rotate(leftT, 90, 40);
        base.forwardTile(0.5, 50);
        base.rotate(leftT, 45, 40);
        dispenser.extend(80,150);
        claw.resetPos(50);
      }
    }
}
