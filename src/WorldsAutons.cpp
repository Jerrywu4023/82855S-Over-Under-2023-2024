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
inline void netQual(bool variation) {
    turnMulti = 2.5;

    // score preload (p)
    intakeA.move(-127);// unhook

    desX = 0;
    desY = 58;
    pros::delay(300);
    intakeA.move(127);
    pros::delay(700);

    moveTurn = false;

    desOrientation = 90;
    pros::delay(400);
    intakeA.move(-127);
    pros::delay(200);

    moveTurn = true;

    desX = 40;
    desY = 50;
    pros::delay(600);

    desX = -35;
    desY = 50;
    pros::delay(800);

    // intake centre middle (1)
    moveTurn = false;

    desOrientation = 340;
    pros::delay(700);

    moveTurn = true;
    intakeA.move(127);

    desX = -35;
    desY = 60;
    pros::delay(300);

    // return to start and release (1)
    turnMulti = 2.9;
    desX = 11;
    desY = -9;
    pros::delay(1200);

    moveTurn = false;
    intakeA.move(-127);
    turnMulti = 2.5;

    desOrientation = 60;
    pros::delay(700);
    
    // move to matchloader
    desOrientation = 220;
    pros::delay(600);

    moveTurn = true;
    intakeA.move(0);

    desX = 30;
    desY = 10.5;
    pros::delay(800);

    // take out matchload (2)
    moveTurn = false;

    desOrientation = 230;
    pros::delay(300);
    wingBL.set_value(true);

    desOrientation = 170;
    pros::delay(500);
    
    wingBL.set_value(false);
    desOrientation = 210;
    pros::delay(500);

    moveTurn = true;

    // score (1) (2)
    desX = 30;
    desY = 60;
    pros::delay(700);

    desX = -25;
    desY = -2;
    pros::delay(600);

    // turn to intake side middle (3)
    moveTurn = false;

    desOrientation = 300;
    pros::delay(700);

    moveTurn = true;
    intakeA.move(127);
    turnMulti = 2.5;

    desX = -31;
    desY = 30;
    pros::delay(1000);
    
    desX = -26.5;
    desY = 60;
    pros::delay(900);

    // score (3) (4)
    moveTurn = false;

    desOrientation = 83;
    pros::delay(800);

    moveTurn = true;
    wingL.set_value(true);

    desX = 30;
    desY = 58;
    pros::delay(100);
    intakeA.move(-127);
    pros::delay(600);
    wingL.set_value(false);

    // ending position
    if (variation) {
        auton = false;
        movePL(-127);
        movePR(-55);
        pros::delay(680);
        movePL(-127);
        movePR(-127);
        pros::delay(300);

        movePL(0);
        movePR(0);
        
    } else {
        auton = false;
        movePL(0);
        movePR(0);
        pros::delay(500);
        movePL(-127);
        movePR(-127);
        pros::delay(400);
        movePL(0);
        movePR(0);
    }
}


/**
 * @brief Matchload side qualifications ##########################################################
 */
inline void matchloadQual(bool variation) {
    // rush centre bottom triball
    if (variation) {
        turnMulti = 3.8;
        driveMulti = 2.3;

        // push (p) to goal with wing
        wingL.set_value(true);

        // move to center bottom triball (1)
        intakeA.move(-127); // unhook

        desX = 4;
        desY = 50;
        pros::delay(500);
        intakeA.move(127);
        wingL.set_value(false);
        pros::delay(1000);

        turnMulti = 2.7;

        desX = -6;
        desY = -12;
        pros::delay(1500);
    } else {
        turnMulti = 2.7;
        intakeA.move(-127);

        desX = -8;
        desY = -14;
        pros::delay(1500);
        intakeA.move(0);
    }

    // return to matchloader
    moveTurn = false;

    desOrientation = 310;
    pros::delay(700);

    moveTurn = true;

    desX = globalX - 18;
    desY = globalY + 10;
    pros::delay(800);

    // take out matchload
    moveTurn = false;

    desOrientation = 340;
    pros::delay(400);
    wingBL.set_value(true);
    pros::delay(100);

    desOrientation = 240;
    pros::delay(1000);
    wingBL.set_value(false);

    desOrientation = 140;
    pros::delay(700);

    // pushed all stolen triballs (1) (2) and elevation (3) to offensive zone
    moveTurn = true;
    turnMulti = 2.7;
    wingL.set_value(true);

    intakeA.move(-127);
    desY = -5;
    desX = 25;
    pros::delay(1500);
    wingL.set_value(false);

    // touch elevation pole
    auton = false;
    moveL(50);
    moveR(50);

    while(pipeCheck.get() > 100) pros::delay(10);

    moveL(0);
    moveR(0);
    pros::delay(2000);
    intakeA.move(0);
}


/**
 * @brief Net side eliminations ##################################################################
 */
inline void netElim(bool variation) {
    turnMulti = 3.8;

    // push preload to goal with wing
    wingR.set_value(true);

    // move to centre middle triball (1)
    intakeA.move(-127);// unhook

    desX = -30;
    desY = 52;
    pros::delay(500);
    intakeA.move(127);
    wingR.set_value(false);
    pros::delay(800);

    // return to starting position
    desX = 13;
    desY = -10;
    pros::delay(800);

    // curve to spin out triball
    desX = -5;
    desY = -10;
    pros::delay(300);

    // release (1)
    intakeA.move(-127);
    pros::delay(500);

    moveTurn = false;

    // move to elevation (2)
    turnMulti = 2.5;
    desOrientation = 272;
    pros::delay(700);

    intakeA.move(127);

    moveTurn = true;
    desX = -32;
    desY = -7;
    pros::delay(1100);

    // return to matchload bar (3)
    desX = 26.5;
    desY = 12;
    pros::delay(1250);

    moveTurn = false;
    
    // take matchload out (3)
    desOrientation = 230;
    pros::delay(300);
    wingBL.set_value(true);

    desOrientation = 160;
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
    pros::delay(300);
    intakeA.move(-127);
    pros::delay(300);

    moveTurn = true;

    desX = 30;
    desY = 65;
    pros::delay(800);

    // return to start
    desX = 5;
    desY = 0;
    pros::delay(800);

    // turn to intake side middle (4)
    moveTurn = false;

    desOrientation = 300;
    pros::delay(700);

    moveTurn = true;
    intakeA.move(127);

    desX = -30;
    desY = 31;
    pros::delay(900);

    // drive in front of centre top (5)
    desX = -25;
    desY = 60;
    pros::delay(900);

    // score (4) (5)
    moveTurn = false;

    desOrientation = 83;
    pros::delay(600);

    moveTurn = true;
    wingL.set_value(true);

    desX = 30;
    desY = 55;
    pros::delay(200);
    intakeA.move(-127);
    pros::delay(700);
    wingL.set_value(false);

    desX = -20;
    desY = 55;
    pros::delay(500);
    auton = false;
}


/**
 * @brief Matchload eliminations #################################################################
 */
inline void matchloadElim(bool variation) {
    turnMulti = 3.8;
    driveMulti = 2.3;

    // push (p) to goal with wing
    wingL.set_value(true);

    // move to center bottom triball (1)
    intakeA.move(-127); // unhook

    desX = 4;
    desY = 50;
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
    desY = 51;
    pros::delay(2500);

    // move back to matchload bar
    desX = -6;
    desY = -13;
    pros::delay(1500);

    moveTurn = false;

    desOrientation = 310;
    pros::delay(700);

    moveTurn = true;

    desX = globalX - 18;
    desY = globalY + 10;
    pros::delay(800);

    // take out matchload (3)
    moveTurn = false;

    desOrientation = 340;
    pros::delay(400);
    wingBL.set_value(true);
    pros::delay(100);

    desOrientation = 220;
    pros::delay(1000);
    wingBL.set_value(false);

    desOrientation = 140;
    pros::delay(700);

    // pushed all stolen triballs (1) (2) and elevation (3) to offensive zone
    moveTurn = true;
    turnMulti = 2.7;
    wingL.set_value(true);

    intakeA.move(-127);
    desY = -5;
    desX = 30;
    pros::delay(1200);
    wingL.set_value(false);

    // return to matchloader
    desX = -20;
    desY = 1;
    pros::delay(1000);

    moveTurn = false;
    desOrientation = 100;
    pros::delay(600);

    auton = false;
    moveL(0);
    moveR(0);
}

/**
 * @brief Skills #################################################################
 */
inline void skills(bool variation) {

    for (int run = 0; run < 2; run++) {
        intakeA.move(-127);
        moveTurn = false;

        desOrientation = 90;
        pros::delay(600);

        moveTurn = true;

        desX = -20;
        desY = 1;
        pros::delay(800);

        moveTurn = false;

        desOrientation = 115;
        pros::delay(600);

        wingBR.set_value(true);
        pros::delay(14000);

        moveTurn = true;
        wingBR.set_value(false);
        wingL.set_value(true);

        desX = 10;
        desY = -12;
        pros::delay(500);

        for (int i = 0; i < 3; i++) {
            desX += 26;
            pros::delay(500);
        }
        pros::delay(500);

        moveTurn = false;

        desOrientation = 70;
        pros::delay(700);

        moveTurn = true;

        desX = 125;
        desY = 60;
        pros::delay(1200);

        wingL.set_value(false);
        desX = 100;
        desY = -5;
        pros::delay(300);

        moveTurn = false;

        desOrientation = 40;
        pros::delay(500);

        moveTurn = true;

        desX = 125;
        desY = 60;
        pros::delay(900);

        desX = 100;
        desY = -5;
        pros::delay(700);

        moveTurn = false;

        desOrientation = 230;
        pros::delay(700);

        moveTurn = true;

        desX = 125;
        desY = 60;
        pros::delay(1200);
        intakeA.move(0);

        if (run == 0) {
            desX = 85;
            desY = -7;
            pros::delay(800);

            moveTurn = false;

            desOrientation = 90;
            pros::delay(700);

            moveTurn = true;

            for (int i = 0; i < 3; i++) {
                desX -= 33;
                desY = -3;
                pros::delay(500);
            }
            pros::delay(500);
        } else {
            desX = 85;
            desY = -13;
            pros::delay(800);

            moveTurn = false;
            hangUp.set_value(true);

            desOrientation = 255;
            pros::delay(700);

            moveTurn = true;

            desX = 30;
            pros::delay(500);

            moveTurn = false;

            desOrientation = 270;
            pros::delay(700);

            moveTurn = true;

            desX = -20;
            pros::delay(2000);

            auton = false;
            hang.set_value(true);
            hangUp.set_value(false);
            odomRelease.set_value(true);
            movePL(0);
            movePR(0);
        }
    }
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