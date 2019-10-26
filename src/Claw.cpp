#include "main.h"

class Claw {
  public:
    pros::Motor m;
    bool moving = false;
    int pastTick = 0;
    int currentTick = 0;
    int confirmedSame = 0;
    Claw(pros::Motor mot): m(mot) {
      m.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      m.tare_position();
    };

    void move(int vel) {
      m.move_velocity(vel);
    }

    void stop() {
      m.move_velocity(0);
    }

    void resetPos(int speed) {
      m.move_absolute(0, speed);
      moving = true;
      while(moving) {
        checkMoving();
        pros::lcd::set_text(1, "Moving");
        pros::delay(10);
      }
      pros::lcd::clear_line(1);
    }

    void checkMoving() {
      currentTick = m.get_position();
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
