#include "main.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"

// Controller ###
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors ###
// Drive
inline pros::Motor LF(14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LM(13, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LB(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

inline pros::Motor RF(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RM(18, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RB(17, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

inline pros::Motor driveMotors[] = {LF, LM, LB, RF, RM, RB};


// Cata - Intake
inline pros::Motor cataA(20, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor intakeA(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);


// Pneumatics ###
// WALL
inline pros::ADIDigitalOut wingL('E');
inline pros::ADIDigitalOut wingR('D');

// Endgame
inline pros::ADIDigitalOut passiveEndgame('C');

// Blocker
inline pros::ADIDigitalOut blocker('A');
inline pros::ADIDigitalOut hang('B');

// Sensors ###
inline pros::Rotation cataPos(7);

inline pros::Distance autonSelect(2);
