#include "PowerOutput.cpp"
#include "pros/misc.h"

// Variables
inline int drivePower;
inline int turnPower;

inline int driverCataState = 2; // states: 0 = up, 1 = down, 2 = auto disabled
inline bool matchloadCataState = false; // states: false = off, true = on
inline bool cataButton;
inline bool cataToggle;
inline bool prevCataToggle = false;
inline bool autoLower = false;
inline bool cataReset;

inline bool intakeButton;
inline bool intakeReverse;
inline bool endgameButtonA;
inline bool endgameButtonB;

inline bool wingROn, wingLOn;

inline bool blockerSwitch = false;
inline bool prevBlocker = false;
inline bool blockerState = false;


/**
 * @brief over under match load styled
 * Toggle + hold active cata
 * Auto lower cata when button pressed
 */
inline void overUnder() {
    // Get controller
    // joysticks
    drivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    turnPower = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * -1;

    // buttons
    intakeButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    intakeReverse = master.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

    cataButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    cataToggle = master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
    cataReset = master.get_digital(pros::E_CONTROLLER_DIGITAL_X);

    wingLOn = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    wingROn = master.get_digital(pros::E_CONTROLLER_DIGITAL_B);

    blockerSwitch = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);

    endgameButtonA = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    endgameButtonB = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);

    // Drive - move drive motors
    movePL(drivePower - turnPower);
    movePR(drivePower + turnPower);

    // Intake
    if (intakeButton) intakeA.move(127);
    else if (intakeReverse) intakeA.move(-127);
    else intakeA.move(0);

    // Cata move
    if (matchloadCataState || cataButton || autoLower) cataA.move(127);
    else cataA.move(0);

    /* Auto lower cata ###
    Automatically lowers cata when desired

    if auto lower == true, lower cata

    auto lower set to true when button pressed
    auto lower set to false when position reached
    */ 
    if (cataReset) autoLower = true; // set auto to true

    if (cataPos.get_position() < 100000) autoLower = false; // set auto to false, 100000 = disabled

    /* Cata and blocker state control ###
    Cata/blocker state switches the instant button pressed
    The instant is when current button state == true
    and previous button state == false
    */

    // Cata state control
    if (cataToggle && !prevCataToggle) matchloadCataState = !matchloadCataState;
    prevCataToggle = cataToggle;

    // Blocker state control
    if (blockerSwitch && !prevBlocker) {
        blockerState = ! blockerState;
        hang.set_value(false); // releases accidental hang
    }
    prevBlocker = blockerSwitch;

    // Wings
    wingL.set_value(wingLOn);
    wingR.set_value(wingROn);

    // Blocker
    blocker.set_value(blockerState);

    // Endgame
    if (endgameButtonA && endgameButtonB) {
        hang.set_value(true);
        passiveEndgame.set_value(true);
    }
}