#include "globals.hpp"

inline void moveL(int velocity) {
	LF.move_velocity(velocity);
	LB.move_velocity(velocity);
	LM.move_velocity(velocity);
	noel.move_velocity(velocity / 3);
}

inline void moveR(int velocity) {
	RF.move_velocity(velocity);
	RB.move_velocity(velocity);
	RM.move_velocity(velocity);
	tofu.move_velocity(velocity / 3);
}

inline void movePL(int power) {
	LF.move(power);
	LB.move(power);
	LM.move(power);
	noel.move(power);
}

inline void movePR(int power) {
	RF.move(power);
	RB.move(power);
	RM.move(power);
	tofu.move(power);
}

inline void HardBreak() {
	moveL(0);
	moveR(0);
	LF.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	RF.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	RB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	LM.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	RM.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	noel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	tofu.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	LF.tare_position();
	LB.tare_position();
	LM.tare_position();
	RM.tare_position();
	RF.tare_position();
	RB.tare_position();
	noel.tare_position();
	tofu.tare_position();
}

inline void driveTare () {
	LB.tare_position();
	LM.tare_position();
	LF.tare_position();
	RM.tare_position();
	RB.tare_position();
	RF.tare_position();
	noel.tare_position();
	tofu.tare_position();
}