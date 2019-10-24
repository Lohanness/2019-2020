#include "main.h"

class Claw {
  public:
    pros::Motor m;
    bool open;
    bool moving;
    bool grabbing = false;
    int ticks;
    int pastTick = 0;
    int currentTick = 0;
    int confirmedSame = 0;
    Claw(int tick, pros::Motor mot): ticks(tick), m(mot) {
      m.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    };



    int getPos() {
      return abs(int(m.get_position()));
    }

    void move(int vel) {
      m.move_velocity(vel);
    }

    void stop() {
      m.move_velocity(0);
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

    void resetEncoder() {
      m.tare_position();
    }
};
