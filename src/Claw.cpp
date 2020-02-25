#include "main.h"

class Claw {
  public:
    pros::Motor m;
    bool moving = false;


    Claw(pros::Motor mot): m(mot) {
      m.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      m.set_gearing(pros::E_MOTOR_GEARSET_36);
      m.tare_position();
    };

    void move(int vel) {
      m.move_velocity(vel);
    }

    void moveTicks(int degrees, int vel) {
        int ticks = degrees*24;
        m.move_relative(degrees, vel);
    }

    void stop() {
      m.move_velocity(0);
    }

    void resetPos(int speed) {
      m.move_absolute(0, speed);
      moving = true;
      while(m.is_stopped() ==1) {
        pros::delay(2);
      }
      moving = false;
      pros::lcd::clear_line(1);
    }

    bool checkMoving() {
      if(m.is_stopped()) {
        return false;
      }
      return true;
    }
};
