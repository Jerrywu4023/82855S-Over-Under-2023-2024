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

	pros::delay(1000);

	// auton select

	autonNum = autonSelect.get();

	pros::lcd::print(0, "auton: %d", autonNum);

	if (autonNum < 100) {
		autonNum = 0;
		thetaReset = 3 * pi / 2;
		pros::lcd::print(1, "close side");
	}
	else if (autonNum < 500) {
		autonNum = 1;
		pros::lcd::print(1, "far side");
	}
	else if (autonNum < 1000) {
		autonNum = 2;
		pros::lcd::print(1, "skills");
	}
	else {
		autonNum = 3;
		pros::lcd::print(1, "old close");
	}

	pros::delay(1000);

}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	pros::Task Odom(odometry);
	pros::Task move(coordMove);
	pros::Task turning(turn);
	pros::Task out(PowerOutput);
	pros::delay(10);

	switch (autonNum) {
		case 0:
			closeSideNew();
			break;
		case 1:
			farSide();
			break;
		case 2:
			skills();
			break;
		case 3:
			closeSide();
			break;
		default: 
			break;
	}
}

void opcontrol() {
	// Variables
	int driveMode = 0;
	auton = false;

	// Control Loop
	while (driveMode != -1) {

		overUnder();

		// Delay cotrol loop to not over work the brain
		pros::delay(10);
	}
}