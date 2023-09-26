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

	bool cataState = 2; // cata states: 0 = up, 1 = down, 2 = auto disabled
	bool cataButton;
	bool cataDisable = false;
	bool prevDisable = false;

	bool intakeButton;
	bool wallButton;
	bool endgameButton;
	bool endgameButton2;


	// Control Loop
	while (driver) {

		// Get controller
		// joysticks
		drivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		turnPower = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * -1;

		// buttons
		intakeButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
		cataButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
		cataDisable = master.get_digital(pros::E_CONTROLLER_DIGITAL_X);

		endgameButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
		endgameButton2 = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

		// Drive - move drive motors
		moveL(drivePower * 2 - turnPower);
		moveR(drivePower * 2 + turnPower);

		/* Intake Cata system ###

		if cata == up (1), run cata
		else if cata button == true, run cata
		else if intake == true, reverse cata (intake will not move when cata moving)
		else let cata motor loose (0 power) */

		if (cataState == 0 || cataButton == true) { // cata is up and not disabled or driver moving cata
			cataR.move(127);
			cataL.move(127);
		} else if (intakeButton == true) { // cata down or disabled, safe to run intake
			cataR.move(-127);
			cataL.move(-127);
		} else { // no need to move cata
			cataR.move(0);
			cataL.move(0);
		}

		/* Cata state control ###
		if disable button pressed, change disable state
		0, 1 --> 2
		2 --> 0 (will set to 1 if cata is down, from code after)

		if cata not disabled
			if pos > 85, state set to 1
			if pos < 10, state set to 0
		*/
		// update disable
		if (cataDisable == true && prevDisable == false) { // the instant that disable button pressed
			if (cataState != 2) cataState = 2;
			else cataState = 0;
		}

		// update state
		if (cataState != 2) { //  auto cata is on
			if (cataPos.get_position() > 85) cataState = 1;
			if (cataPos.get_position() < 10) cataState = 0;
		}

		// Delay cotrol loop to not over work the brain
		pros::delay(20);
	}
}