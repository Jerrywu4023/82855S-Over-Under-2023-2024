#include "main.h"
#include "pros/adi.hpp"

// Controller ###
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors ###
// Drive
inline pros::Motor LF(1, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LM(19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor LB(10, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

inline pros::Motor RF(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RM(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor RB(9, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);


// Cata - Intake
inline pros::Motor cataL(17, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor cataR(14, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);


// Pneumatics ###
// Intake
inline pros::ADIDigitalOut intakeA('D');

// WALL
inline pros::ADIDigitalOut wallL(10, 'C');
inline pros::ADIDigitalOut wallR(10, 'A');

// Endgame
inline pros::ADIDigitalOut endgame(10, 'E');


// Sensors ###
// Rotation Sensor
inline pros::Rotation SlEncode(14);
inline pros::Rotation SsEncode(15);

inline pros::Rotation cataPos(16);

// Inertial Sensor
inline pros::Imu imu1(7);
inline pros::Imu imu2(8);
inline double imu1Multi = 1;
inline double imu2Multi = 1;