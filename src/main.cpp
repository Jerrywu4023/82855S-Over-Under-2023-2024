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

	bool cataState = 0;
	bool cataButton;

	bool intakeButton;
	bool wallButton;
	bool endgameButton;
	bool endgameButton2;


	// Control Loop
	while (driver) {

		// Get controller
		drivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		turnPower = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		intakeButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
		cataButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
		wallButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);
		endgameButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
		endgameButton2 = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);


		// move drive motors
		moveL(drivePower * 2 + turnPower);
		moveR(drivePower * 2 - turnPower);

		pros::delay(20);



	}
}