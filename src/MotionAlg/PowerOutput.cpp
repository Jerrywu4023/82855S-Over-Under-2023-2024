#include "PowerControl.cpp"

/**
 * @brief Functions to move motors based on drive and turn powers
 * @param motors array of all drive motors with first 3 on left followed by 3 right
 */

inline void PowerOutput (pros::Motor motors[]) {
    while (auton) {
        if (!disableOdomControl) {
            // move left
            motors[0].move(desDrive + desTurn);
            motors[1].move(desDrive + desTurn);
            motors[2].move(desDrive + desTurn);

            // move right
            motors[3].move(desDrive - desTurn);
            motors[4].move(desDrive - desTurn);
            motors[5].move(desDrive - desTurn);
        }

        pros::delay(5);
    }
}