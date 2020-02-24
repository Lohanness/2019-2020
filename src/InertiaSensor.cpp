
#include "main.h"


class Inertia {
public:
  pros::Imu sensor;
  Inertia(pros::Imu se): sensor(se) {};

  void initialize() {
    sensor.reset();
    pros::delay(2000);
  }

  int getRotation() {
    return (int)sensor.get_rotation();
  }

};
