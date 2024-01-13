#include "Autons.cpp"
#include "pros/misc.h"

void initialize() {
	pros::lcd::initialize();
	
	// reset pneumatics
	passiveEndgame.set_value(false);
	blocker.set_value(false);
	hang.set_value(false);
	wingL.set_value(false);
	wingR.set_value(false);

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

	autonNum = autonSelect.get_angle();
	double size = 40; // angle in degrees per auton option

	pros::lcd::print(0, "auton: %d", autonNum);

	if (autonNum < size * 1) {
		autonNum = 1;
		thetaReset = 3 * pi / 2; // 270 deg
		pros::lcd::print(1, "close side");
	}
	else if (autonNum < size * 2) {
		autonNum = 2;
		pros::lcd::print(1, "far side");
	}
	else if (autonNum < size * 3) {
		autonNum = 3;
		pros::lcd::print(1, "aaa");
	}
	else if (autonNum < size * 4) {
		autonNum = 4;
		pros::lcd::print(1, "aaa");
	}
	else if (autonNum < size * 5) {
		autonNum = 5;
		pros::lcd::print(1, "aaa");
	}
	else if (autonNum < size * 6) {
		autonNum = 6;
		pros::lcd::print(1, "aaa");
	}
	else if (autonNum < size * 7) {
		autonNum = 7;
		pros::lcd::print(1, "aaa");
	}
	else if (autonNum < size * 8) {
		autonNum = 8;
		pros::lcd::print(1, "aaa");
	}
	else {
		autonNum = 0;
		pros::lcd::print(1, "aaa");
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
		case 1:
			netSideQ();
			break;	
		case 2:
			loadSideQ();
			break;
		case 3:
			skills();
			break;
		case 4:
			netSideOld();
			break;
		default: 
			break;
	}
}

void opcontrol() {
	pros::lcd::print(0,"b");
	// Variables
	int driveMode = 0;
	auton = false;

	pros::Task Odom(odometry);
	
	// Control Loop
	while (driveMode != -1) {
		
		overUnder();

		// Delay cotrol loop to not over work the brain
		pros::delay(10);
	}
}