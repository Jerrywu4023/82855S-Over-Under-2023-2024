#include "main.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"

// Controller ###
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors ###
// Drive
inline pros::Motor LF(18, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LM(19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LB(20, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

inline pros::Motor RF(8, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RM(5, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RB(10, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

inline pros::Motor driveMotors[] = {LF, LM, LB, RF, RM, RB};


// Cata - Intake
inline pros::Motor cataA(20, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor intakeA(15, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);


// Pneumatics ###
// Front Wings
inline pros::ADIDigitalOut wingL('G');
inline pros::ADIDigitalOut wingR('H');

// Back Wings
inline pros::ADIDigitalOut wingBL('E');
inline pros::ADIDigitalOut wingBR('F');

// Hang
inline pros::ADIDigitalOut hangUp('D');
inline pros::ADIDigitalOut hang('C');

// Odom Release
inline pros::ADIDigitalOut odomRelease('B');

// Sensors ###
inline pros::Rotation cataPos(11);

inline pros::ADIPotentiometer autonSelect( 'A', pros::E_ADI_POT_V2);
