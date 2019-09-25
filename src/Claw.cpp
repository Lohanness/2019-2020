#include "main.h"

class Claw {
  public:
    pros::Motor m;
    bool open;
    bool moving;
    int ticks;
    int pastTick = 0;
    int currentTick = 0;
    int confirmedSame = 0;
    Claw(int tick, pros::Motor mot): ticks(tick), m(mot) {};

    void go(int vel) {
      if(open) {
        m.move_relative(ticks,vel);
      } else {
        m.move_relative(ticks,-1*vel);
      }
    }

    int getPos() {
      return abs(int(m.get_position()));
    }

    void move(int vel) {
      m.move_velocity(vel);
    }
    void checkMoving() {
      currentTick = getPos();
      if(currentTick == pastTick) {
        if(confirmedSame == 4) {
          moving = false;
          confirmedSame = 0;
        }
        confirmedSame+=1;
      } else {
        pastTick = currentTick;
        confirmedSame = 0;
      }
    }
};
