#include "DriverModes.cpp"

inline int autonNum;
inline bool variation = false;

inline void autoStart() {
	pros::Task Odom(odometry);
	pros::Task move(coordMove);
	pros::Task turning(turn);
	pros::Task out(PowerOutput);
	pros::delay(10);
}

/**
 * @brief Net side qualifications ################################################################
 */
inline void netQual(bool variation) {}


/**
 * @brief Matchload side qualifications ##########################################################
 */
inline void matchloadQual(bool variation) {}


/**
 * @brief Net side eliminations ##################################################################
 */
inline void netElim(bool variation) {
    turnMulti = 3.8;

    // push preload to goal with wing
    wingR.set_value(true);

    // move to centre middle triball (1)
    intakeA.move(-127);// unhook

    desX = -28;
    desY = 51;
    pros::delay(500);
    intakeA.move(127);
    wingR.set_value(false);
    pros::delay(1000);

    // return to starting position
    desX = 7;
    desY = -5;
    pros::delay(900);

    // curve to spin out triball
    desX = -10;
    desY = -15;
    pros::delay(300);

    // release (1)
    intakeA.move(-127);
    pros::delay(500);

    moveTurn = false;

    // move to elevation (2)
    turnMulti = 2.5;
    desOrientation = 275;
    pros::delay(700);

    intakeA.move(127);

    moveTurn = true;
    desX = -35;
    desY = -6;
    pros::delay(1200);

    // return to matchload bar (3)
    desX = 29;
    desY = 10;
    pros::delay(1200);

    moveTurn = false;
    
    // take matchload out (3)
    desOrientation = 220;
    pros::delay(300);
    wingBL.set_value(true);

    desOrientation = 170;
    pros::delay(500);
    
    wingBL.set_value(false);
    desOrientation = 210;
    pros::delay(500);

    moveTurn = true;

    // score matchload, centre middle, preload in goal (p)(1)(3)
    desX = 30;
    desY = 60;
    pros::delay(700);

    // turn around and score elevation (2)
    desX = 10;
    desY = 10;
    pros::delay(300);

    moveTurn = false;

    desOrientation = 0;
    pros::delay(700);

    moveTurn = true;
    intakeA.move(-127);

    desX = 30;
    desY = 60;
    pros::delay(700);

    // return to start
    desX = 5;
    desY = 0;
    pros::delay(800);

    // turn to intake side middle (4)
    moveTurn = false;

    desOrientation = 310;
    pros::delay(600);

    moveTurn = true;
    intakeA.move(127);

    desX = -30;
    desY = 30;
    pros::delay(1000);

    // drive in front of centre top (5)
    desX = -20;
    desY = 55;
    pros::delay(600);

    // score (4) (5)
    moveTurn = false;

    desOrientation = 90;
    pros::delay(700);

    moveTurn = true;
    wingL.set_value(true);

    desX = 30;
    desY = 50;
    pros::delay(300);
    intakeA.move(-127);
    pros::delay(700);
    wingL.set_value(false);

    desX = 0;
    desY = 50;
    pros::delay(500);
    auton = false;
}


/**
 * @brief Matchload eliminations #################################################################
 */
inline void matchloadElim(bool variation) {
    turnMulti = 3.8;

    // push (p) to goal with wing
    wingL.set_value(true);

    // move to center bottom triball (1)
    intakeA.move(-127); // unhook

    desX = 6;
    desY = 48;
    pros::delay(500);
    intakeA.move(127);
    wingL.set_value(false);
    pros::delay(1000);

    // move back to starting position
    desX = -10;
    desY = -10;
    pros::delay(1200);

    // turn to elevation pole and release (1)
    moveTurn = false;

    desOrientation = 90;
    pros::delay(700);
    intakeA.move(-127);
    pros::delay(700);

    // turn towards centre middle and intake (2)
    desOrientation = 20;
    pros::delay(700);

    moveTurn = true;
    intakeA.move(127);
    
    desX = 22;
    desY = 48;
    pros::delay(2500);

    // move back to matchload bar
    desX = -21;
    desY = -3;
    pros::delay(1500);

    // take out matchload (3)
    moveTurn = false;

    desOrientation = 340;
    pros::delay(800);
    wingBL.set_value(true);
    pros::delay(100);

    desOrientation = 220;
    pros::delay(500);
    wingBL.set_value(false);

    desOrientation = 100;
    pros::delay(700);

    // pushed all stolen triballs (1) (2) and elevation (3) offensive zone
    moveTurn = true;

    desX = 0;
    desY = -5;
    pros::delay(800);

    intakeA.move(-127);
    desX = 20;
    pros::delay(800);
}


/**
 * @brief Tester code #################################################################
 */
inline void test() {
    //moveTurn = false;
    desOrientation = 90;
    desX = 20;
    desY = 30;
    pros::delay(3000);

    desX = 20;
    desY = -20;
    desOrientation = 120;
    pros::delay(3000);

    desX = -10;
    desY = 10;
    desOrientation = 195;
    pros::delay(3000);

    desX = 0;
    desY = 0;
    desOrientation = 0;
    pros::delay(3000);

    moveTurn = false;
    desOrientation = 90;
    pros::delay(1000000);
}