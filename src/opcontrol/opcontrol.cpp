#include "main.h"
pros::ADIEncoder lEncode(1,false);
pros::ADIEncoder rEncode(3,true);
void resetPress() {
	lEncode.reset();
	rEncode.reset();
}
void opcontrol() {

	//Identify which controller is the master constroller
	pros::lcd::initialize();
  pros::lcd::register_btn1_cb(resetPress);

	pros::Controller master(pros::E_CONTROLLER_MASTER);

	//Identify all the motors
	pros::Motor fRight(10);
	pros::Motor bRight(20);
	pros::Motor fLeft(9);
	pros::Motor bLeft(19);
	lEncode.reset();
	rEncode.reset();

	while (true) {
		pros::lcd::set_text(1,"Left Encoder: " + std::to_string(lEncode.get_value()));
		pros::lcd::set_text(2,"Right Encoder: " + std::to_string(rEncode.get_value()));
		int leftY = master.get_analog(ANALOG_LEFT_Y);
		int leftX = master.get_analog(ANALOG_LEFT_X);

		fRight = leftY-leftX;
		bRight = leftY-leftX;
		fLeft = leftY+leftX;
		bLeft = leftY+leftX;

		pros::delay(10);
	}
}
