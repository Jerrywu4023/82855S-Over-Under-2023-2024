#include "PID.cpp"
#include "pros/misc.h"

// Variables
inline int drivePower;
inline int turnPower;

inline int driverCataState = 2; // states: 0 = up, 1 = down, 2 = auto disabled
inline bool matchloadCataState = false; // states: false = off, true = on
inline bool cataButton;
inline bool prevCataButton = false;

inline bool cataDisable = false;
inline bool prevDisable = false;

inline bool intakeButton;
inline bool intakeReverse;
inline bool wallButton;
inline bool endgameButton;
inline bool endgameButton2;


/**
 * @brief Driver mode
 * press active catapult
 * auto lower catapult
 */
inline void basicDriver() {
    // Get controller
    // joysticks
    drivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    turnPower = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * -1;

    // buttons
    intakeButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    cataButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    cataDisable = master.get_digital(pros::E_CONTROLLER_DIGITAL_X);

    endgameButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    endgameButton2 = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    // Drive - move drive motors
    moveL(drivePower * 2 - turnPower);
    moveR(drivePower * 2 + turnPower);

    /* Intake Cata system ###

    if cata == up (1), run cata
    else if cata button == true, run cata
    else if intake == true, reverse cata (intake will not move when cata moving)
    else let cata motor loose (0 power) */

    if (driverCataState == 0 || cataButton == true) { // cata is up and not disabled or driver moving cata
        cataR.move(127);
        cataL.move(127);
    } else if (intakeButton == true) { // cata down or disabled, safe to run intake
        cataR.move(-127);
        cataL.move(-127);
    } else { // no need to move cata
        cataR.move(0);
        cataL.move(0);
    }

    /* Cata state control ###
    if disable button pressed, change disable state
    0, 1 --> 2
    2 --> 0 (will set to 1 if cata is down, from code after)

    if cata not disabled
        if pos > 85, state set to 1
        if pos < 10, state set to 0
    */
    // update disable
    if (cataDisable == true && prevDisable == false) { // the instant that disable button pressed
        if (driverCataState != 2) driverCataState = 2;
        else driverCataState = 0;
    }

    // update state
    if (driverCataState != 2) { //  auto cata is on
        if (cataPos.get_position() > 85) driverCataState = 1;
        if (cataPos.get_position() < 10) driverCataState = 0;
    }
}


/**
 * @brief over under match load styled
 * Toggle active cata
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
    cataDisable = master.get_digital(pros::E_CONTROLLER_DIGITAL_X);

    endgameButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    endgameButton2 = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    // Drive - move drive motors
    moveL(drivePower * 2 - turnPower);
    moveR(drivePower * 2 + turnPower);

    /* Intake Cata system ###
    if state == 0, stop cata
    if state == 1, run cata

    if intake button, reverse cata
    if intake reverse, run cata
    */

    if (matchloadCataState || intakeReverse) {
        cataL.move(127);
        cataR.move(127);
    } else if (intakeButton) {
        cataL.move(-127);
        cataR.move(-127);
    } else {
        cataL.move(0);
        cataR.move(0);
    }


    /* Cata state control ###
    Cata state switches the instant button pressed
    The instant is when current button state == true
    and previous button state == false
    */

    // update state
    if (cataButton && !prevCataButton) {
        matchloadCataState = !matchloadCataState;
    }
}