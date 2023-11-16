#include "Autons.cpp"
#include "pros/misc.h"

void initialize() {
	pros::lcd::initialize();
	
	// reset pneumatics
	intakeA.set_value(false);
	endgame.set_value(false);
	wingL.set_value(wingLState);
	wingR.set_value(wingRState);

	// calibrate imu
	imu1.reset();
	imu2.reset();

	// reset drive
	driveTare();

	// reset rot sensor
	SlEncode.reset_position();
	SsEncode.reset_position();
	cataPos.reset();

	pros::delay(2000);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	// Variables
	int driveMode = 0;

	
	pros::Task Odom(odometry);

	// Control Loop
	while (driveMode != -1) {
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) driveMode = 0;
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) driveMode = 1;

		if (driveMode == 0) overUnder();
		else basicDriver();

		// Delay cotrol loop to not over work the brain
		pros::delay(10);
	}
}