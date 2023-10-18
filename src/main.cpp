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

	int motorPower;
	bool cylinderButton;

	int imuHeading;
	double rotPos;
	int limPos;

	// Control Loop
	while (driver) {
		// Get controller
		// joysticks
		motorPower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		// buttons
		cylinderButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);

		// Get sensors
		imuHeading = imu.get_heading();
		rotPos = rot.get_position();
		limPos = limSwitch.get_value();
		
		motor.move(motorPower);
		pneumatics.set_value(cylinderButton);

		// lcd print
		pros::lcd::print(0, "heading: %d", imuHeading);
		pros::lcd::print(1, "rotation: %f", rotPos);
		pros::lcd::print(2, "lim switch: %d", limPos);

		// Delay cotrol loop to not over work the brain
		pros::delay(20);
	}
}