#include "WorldsAutons.cpp"
#include "pros/misc.h"

void initialize() {
	pros::lcd::initialize();
	
	// reset pneumatics
	hang.set_value(false);
	hangUp.set_value(false);
	wingL.set_value(false);
	wingR.set_value(false);
	wingBL.set_value(false);
	wingBR.set_value(false);
	odomRelease.set_value(false);

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
	variation = 
	autonNum = autonSelect.get_angle();
	double size = 40; // angle in degrees per auton option

	pros::lcd::print(0, "auton: %d", autonNum);

	if (autonNum < size * 1) {
		autonNum = 0;
		pros::lcd::print(1, "net qual");
	}
	else if (autonNum < size * 2) {
		autonNum = 1;
		pros::lcd::print(1, "matchload qual");
	}
	else if (autonNum < size * 3) {
		autonNum = 2;
		pros::lcd::print(1, "net elim");
	}
	else if (autonNum < size * 4) {
		autonNum = 3;
		pros::lcd::print(1, "matchload elim");
	}
	else if (autonNum < size * 5) {
		autonNum = 4;
		pros::lcd::print(1, "matchload elim");
	}
	else if (autonNum < size * 6) {
		autonNum = 5;
		pros::lcd::print(1, "skills");
	}
	else if (autonNum < size * 7) {
		autonNum = 6;
		pros::lcd::print(1, "test");
	}
	else if (autonNum < size * 8) {
		autonNum = 7;
		pros::lcd::print(1, "net elim");
	}
	else {
		autonNum = -1;
		pros::lcd::print(1, "disabled");
	}

	pros::delay(1000);

}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	switch (autonNum) {
		case 0:
			autoStart();
			netQual(variation);
			break;
		case 1:
			autoStart();
			matchloadQual(variation);
			break;
		case 2:
			autoStart();
			netElim(variation);
			break;
		case 3:	
			autoStart();
			matchloadElim(variation);
			break;
		case 4:
			autoStart();
			break;
		case 5:
			autoStart();
			break;
		case 6:
			autoStart();
			break;
		case 7:
			autoStart();
			test();
			break;
		default: 
			auton = false;
			break;
	}
}

void opcontrol() {
	pros::lcd::print(0,"b");
	pros::Task Odom(odometry);

	if (autonNum == 6) {
		thetaReset = 3 * pi / 2;
		autoStart();
		//driverSkills();
	}

	// Variables
	int driveMode = 0;
	auton = false;
	
	odomRelease.set_value(true);

	// Control Loop
	while (driveMode != -1) {
		overUnder();
		// Delay cotrol loop to not over work the brain
		pros::delay(10);
	}
}