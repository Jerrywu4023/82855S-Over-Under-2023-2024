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
	pros::Task move(coordMove);
	pros::Task turning(turn);
	pros::Task out(PowerOutput);
	pros::delay(10);
	farSide();

	// Control Loop
	while (driveMode != -1) {

		overUnder();

		// Delay cotrol loop to not over work the brain
		pros::delay(10);
	}
}