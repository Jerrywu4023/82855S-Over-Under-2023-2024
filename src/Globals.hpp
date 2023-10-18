#include "main.h"
#include "pros/adi.hpp"

// Controller ###
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors ###
// Drive
inline pros::Motor motor(17, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);


// Pneumatics ###
inline pros::ADIDigitalOut pneumatics(10, 'A');


// Sensors ###
// Rotation Sensor
inline pros::Rotation rot(16);

// Inertial Sensor
inline pros::Imu imu(7);

// Lim Switch
inline pros::ADIDigitalIn limSwitch({{10, 'A'}});