#include "MotionAlg\PowerControl.cpp"
#include "PID.cpp"

/**
 * @brief Functions to move motors based on drive and turn powers
 * @param motors array of all drive motors with first 3 on left followed by 3 right
 */

inline void PowerOutput () {
    while (auton) {
        if (!disableOdomControl) {
            // move left
            movePL((desDrive + desTurn) * 1);

            // move right
            movePR((desDrive - desTurn) * 1);
        }

        pros::lcd::print(2, "distance: %f", distance);
        pros::lcd::print(6, "desTurn: %f", desTurn);

        pros::delay(5);
    }
}