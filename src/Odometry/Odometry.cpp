#include "OdomVar.cpp"
#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include <iostream>

/**
 * @file Odom.cpp
 * @author Jerry Wu
 * @brief basic odom code
 * @version 0.1
 * @date 2023-10-12
 * 
 * Odometry tracking with two imu and two tracking wheels left and side
 * Change in angle is counterclockwise positive
 */

inline void odometry (pros::Imu imu1, pros::Imu imu2, pros::Rotation Slencode, pros::Rotation Ssencode) {
    std::cout<<"aaa";
}