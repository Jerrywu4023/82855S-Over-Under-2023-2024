#include "PID.cpp"
#include "pros/misc.h"

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	// Variables
	bool driver = true;

	int drivePower;
	int turnPower;

	// Control Loop
	while (driver) {

		// Get controller
		drivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		turnPower = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		// move drive motors
		moveL(drivePower * 2 + turnPower);
		moveR(drivePower * 2 - turnPower);

		pros::delay(20);
	}
}