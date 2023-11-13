#include "main.h"
#include "pros/adi.hpp"

// Controller ###
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors ###
// Drive
inline pros::Motor LF(20, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LM(19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LB(10, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

inline pros::Motor RF(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RM(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RB(9, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

inline pros::Motor driveMotors[] = {LF, LM, LB, RF, RM, RB};


// Cata - Intake
inline pros::Motor cataL(17, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor cataR(14, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);


// Pneumatics ###
// Intake
inline pros::ADIDigitalOut intakeA('F');

// WALL
inline pros::ADIDigitalOut wingL('D');
inline pros::ADIDigitalOut wingR('E');

// Endgame
inline pros::ADIDigitalOut endgame('C');


// Sensors ###
inline pros::Rotation cataPos(7);
