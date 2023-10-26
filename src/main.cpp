#include "DriverModes.cpp"
#include "pros/misc.h"

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	// Variables
	int driveMode = 0;

	// Control Loop
	while (driveMode != -1) {
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) driveMode = 0;
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) driveMode = 1;

		if (driveMode == 0) overUnder();
		else basicDriver();

		// Delay cotrol loop to not over work the brain
		pros::delay(20);
	}
}