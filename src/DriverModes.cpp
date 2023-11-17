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

inline bool cataDisable = false;
inline bool prevDisable = false;

inline bool intakeButton;
inline bool intakeReverse;
inline bool wallButton;
inline bool endgameButton;
inline bool endgameButton2;

inline bool intakeExtend;
inline bool prevExtend = false;
inline bool intakePistState = false;

inline bool wingOn, wingLOn, wingROn, wingOff;
inline int wingLState = 0;
inline int wingRState = 0;

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

    endgameButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    endgameButton2 = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    wingOn = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    wingLOn = master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
    wingROn = master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
    wingOff = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);

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

    /*
    Wings ###
    0 = off, 1 = on

    BUTTON    LEFT      RIGHT
    wingOn    1         1
    wingLOn   1         no change
    wingROn   no change 1
    wingOff   0         0
    */
    
    // left wing
    if (wingOn || wingLOn) wingLState = 1;
    if (wingOff) wingLState = 0;

    // right wing
    if (wingOn || wingROn) wingRState = 1;
    if (wingOff) wingRState = 0;

    // set wing state
    wingL.set_value(wingLState);
    wingR.set_value(wingRState);
}


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
    intakeExtend = master.get_digital(pros::E_CONTROLLER_DIGITAL_B);
    cataButton = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    cataToggle = master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
    cataReset = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);

    wingLOn = master.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    wingROn = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    // Drive - move drive motors
    movePL(drivePower - turnPower);
    movePR(drivePower + turnPower);

    /* Intake Cata system ###
    if toggleState == 0, stop cata
    if toggleState == 1, run cata

    if intake button, reverse cata
    if intake reverse, run cata 

    if holding cata button, run cata
    */

    if (matchloadCataState || intakeReverse || cataButton || autoLower) {
        cataL.move(127);
        cataR.move(127);
    } else if (intakeButton) {
        cataL.move(-127);
        cataR.move(-127);
    } else {
        cataL.move(0);
        cataR.move(0);
    }

    /* Auto lower cata ###
    Automatically lowers cata when desired

    if auto lower == true, lower cata

    auto lower set to true when button pressed
    auto lower set to false when position reached
    */ 
    if (cataReset) autoLower = true; // set auto to true

    if (cataPos.get_position() < 26000) autoLower = false; // set auto to false, 100000 = disabled


    /* Cata state control ###
    Cata state switches the instant button pressed
    The instant is when current button state == true
    and previous button state == false
    */

    // update state
    if (cataToggle && !prevCataToggle) matchloadCataState = !matchloadCataState;

    prevCataToggle = cataToggle;

    /*
    Intake extend ###
    button press to change intake extension state
    */
    intakeA.set_value(intakePistState);

    if (intakeExtend && !prevExtend) intakePistState = !intakePistState;

    prevExtend = intakeExtend;

    /*
    Wings ###
    0 = off, 1 = on

    BUTTON    LEFT      RIGHT
    wingOn    1         1
    wingLOn   1         no change
    wingROn   no change 1
    wingOff   0         0
    */
    
    // left wing
    if (wingOn || wingLOn) wingLState = 1;
    if (wingOff) wingLState = 0;

    // right wing
    if (wingOn || wingROn) wingRState = 1;
    if (wingOff) wingRState = 0;

    // set wing state
    wingL.set_value(wingLOn);
    wingR.set_value(wingROn);
}