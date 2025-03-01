#include "OdomVar.cpp"
#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "main.h"
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

inline void odometry () {    
    // constant loop to update odom values
    pros::lcd::print(0, "A");
    while (enableOdom) {
        // Get encoder values
        totalL = SlEncode.get_position();
        totalS = SsEncode.get_position();

        // Convert encoder values to distance traveled
        currL = totalL * (pi / 36000) * (wheelL);
        currS = totalS * (pi / 36000) * (wheelS);

        // Get the change in tracking wheel distance
        deltL = currL - prevL;
        deltS = currS - prevS;

        // Update previous tracking wheel distances
        prevL = currL;
        prevS = currS;

        // Get absoulte orientation
        imuRot1 = imu1.get_rotation() * imu1Multi + imu1Increase;
        imuRot2 = imu2.get_rotation() * imu2Multi;
        theta1 = thetaReset + ((imuRot1 + imuRot1) * pi / 360);
        heading = theta1 * (180 / pi);

        // Get change in angle
        deltTheta = theta1 - theta0;

        // Get average orientation (half angle) for calculating global offset
        thetaMean = (theta0 + theta1) / 2;

        // Update previous angle
        theta0 = theta1;

        // Calculate offset distance of local curves - local offset
        if (deltTheta == 0) { // no angle change
            deltX = deltS;
            deltY = deltL;
        } else { // angle change
            deltX = (2 * sin(deltTheta / 2)) * (deltS / deltTheta - Ss);
			deltY = (2 * sin(deltTheta / 2)) * (deltL / deltTheta - Sl);
        }

        // Convert local offset to global offset
        offTheta = atan2f(deltY, deltX);
        offRadius = sqrt(pow(deltX, 2) + pow(deltY, 2));
        offTheta -= thetaMean; // get offTheta according to current orientation
        globalDeltX = cos(offTheta) * offRadius;
        globalDeltY = sin(offTheta) * offRadius;

        // Add the current global offset to the previous global position
        globalX += globalDeltX;
        globalY += globalDeltY;

        // Convert heading to the range [0, 360)
        while (heading > 360) {
			heading -= 360;
		}
        while (heading < 0) {
            heading += 360;
        }

        // Print values
        pros::lcd::print(0, "currL: %f", currL);
        pros::lcd::print(1, "currS: %f", currS);
        pros::lcd::print(3, "X: %f", globalX);
        pros::lcd::print(4, "Y: %f", globalY);
        pros::lcd::print(5, "Heading: %f", heading);

        // Delay
        pros::delay(5);
    }
}