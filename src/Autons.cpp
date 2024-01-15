#include "DriverModes.cpp"

inline int autonNum;

inline void loadSideQ () {
    // push alliance triball to opponent goal
    desX = 22;
    desY = -40;
    pros::delay(1200);

    // drive back to match loader
    turnMulti = 3;

    desX = 8;
    desY = -10;
    pros::delay(1200);

    // turn to match loader
    moveTurn = false;

    desOrientation = 330;
    pros::delay(500);

    // open wall
    wingR.set_value(true);

    // push triball out matchloader
    moveTurn = true;

    for (int i = 0; i < 5; i++) {
        desX -= 3;
        desY += 3;
        pros::delay(300);
    }

    desX -= 40;

    pros::delay(1000);

    wingR.set_value(false);

    desX += 55;

    pros::delay(1500);

    // turn to middle of opponent offense zone
    moveTurn = false;

    desOrientation = 40;
    pros::delay(500);

    // drive to middle of opponent offense zone
    moveTurn = true;

    desX = -10;
    desY = -50;
    pros::delay(1500);

    // turn to pipe and open wall
    moveTurn = false;

    desOrientation = 270;
    pros::delay(800);

    wingR.set_value(true);
    wingL.set_value(true);

    // push triballs over pipe
    moveTurn = true;

    desX -= 40;
    pros::delay(1000);

    wingL.set_value(false);
    wingR.set_value(false);

    // drive back
    desX += 30;
    pros::delay(800);

    // turn to elevation pole
    moveTurn = false;

    desOrientation = 0;
    pros::delay(800);

    // touch elevation pole
    moveTurn = true;

    desX = -30;
    desY = -15;
    pros::delay(1000);

    desX = -50;
    pros::delay(1000);

    // touch pole
    moveTurn = false;

    desOrientation = 300;
    pros::delay(1000);
}

// ##############################################################################################
// ##############################################################################################

inline void netSideOld () {
    turnMulti = 3;

    globalX = 10;

    // turn to matchloader
    moveTurn = false;

    desOrientation = 30;
    pros::delay(500);

    wingR.set_value(true);

    // push alliance triball and matchload to alliance goal
    moveTurn = true;

    desX = 10;

    for (int i = 0; i < 3; i++) {
        desX += 2;
        desY += 4;
        pros::delay(200);
    }

    desX = 25;
    desY = 40;

    pros::delay(500);

    wingR.set_value(false);

    pros::delay(1000);

    wingR.set_value(false);

    // move back to starting pos
    desX = 5;
    desY = -8;
    pros::delay(1000);

    // turn to elevation and intake triball
    moveTurn = false;

    desOrientation = 270;
    pros::delay(800);

    intakeA.move(127);

    moveTurn = true;

    desX = -37;
    desY = -8;
    pros::delay(1800);

    // move back to starting pos and curve to the side    
    desX = 10;
    desY = -8;

    pros::delay(1500);

    moveTurn = false;
    
    desOrientation = 330;
    pros::delay(500);
    
    moveTurn = true;

    turnMulti += 1;

    // move to middle
    desX = -35;
    desY = 55;
    pros::delay(1200);

    // turn to goal
    moveTurn = false;
    
    desOrientation = 90;
    pros::delay(300);

    // outtake triball
    wingL.set_value(true);
    wingR.set_value(true);

    intakeA.move(-127);
    pros::delay(300);

    // close intake and push triballs
    intakeA.move(0);

    moveTurn = true;

    turnMulti -= 1;

    desX = 15;
    desY = 55;
    pros::delay(1500);

    // touch pole
    desX = -60;
    desY = 25;
    pros::delay(1000);

    wingL.set_value(false);
    wingR.set_value(false);


    moveTurn = false;
    
    desOrientation = 180;
    pros::delay(800);
    
    moveTurn = true;
    desY -= 50;
    desX -= 10;
    pros::delay(1000);
    
} 

// ##############################################################################################
// ##############################################################################################

inline void skills () {
    // move to matchlaod
    turnMulti = 2;

    desX = -10;
    desY = 15;
    pros::delay(500);

    // turn to shoot
    moveTurn = false;

    desOrientation = 335;

    pros::delay(500);

    // matchload
    cataA.move(127);

    pros::delay(42000);

    intakeA.move(0);

    imu1Increase = 0;

    // move across field
    desOrientation = -180;
    pros::delay(1000);

    moveTurn = true;

    desX = -5;
    desY = -15;

    for (int i = 0; i < 5; i++) {
        desY -= 18;
        pros::delay(500);
    }

    pros::delay(1000);

    // push right side
    wingL.set_value(false);
    wingR.set_value(false);

    moveTurn = false;

    desOrientation = 160;
    pros::delay(500);

    desOrientation = 160;
    pros::delay(500);

    moveTurn = true;

    desX = 45;
    desY = -120;
    pros::delay(1200);

    wingL.set_value(false);
    wingR.set_value(false);

    desX = 10;
    desY = -90;
    pros::delay(1000);

    moveTurn = false;

    desOrientation = 250;
    pros::delay(500);

    moveTurn = true;

    desX = 60;
    desY = -55;
    pros::delay(1200);

    // push middle 1
    wingL.set_value(true);
    wingR.set_value(true);

    moveTurn = false;

    desOrientation = 150;
    pros::delay(500);

    desOrientation = 170;
    pros::delay(500);
    
    moveTurn = true;
    
    desX = 60;
    desY = -105;
    pros::delay(1500);

    wingL.set_value(false);
    wingR.set_value(false);

    desX = 80;
    desY = -55;
    pros::delay(1500);

    // push middle 2
    wingL.set_value(true);
    wingR.set_value(true);

    moveTurn = false;

    desOrientation = 150;
    pros::delay(500);

    desOrientation = 190;
    pros::delay(500);
    
    moveTurn = true;
    
    desX = 75;
    desY = -105;
    pros::delay(1500);

    wingL.set_value(false);
    wingR.set_value(false);

    desX = 95;
    desY = -55;
    pros::delay(1500);

    /*// push left side
    desY = -85;
    pros::delay(1000);

    moveTurn = false;

    desOrientation = 230;
    pros::delay(800);

    wingL.set_value(true);
    wingR.set_value(true);

    moveTurn = true;

    desX = 75;
    desY = -105;
    pros::delay(1500);

    wingL.set_value(false);
    wingR.set_value(false);

    desX = 90;
    desY = -90;
    pros::delay(1000);*/
}

inline void test() {
    desX = 10;
    desY = 20;
    pros::delay(100000);
}

inline void netSideQ() {
    turnMulti = 3;

    globalX = -35;
    globalY = -8;

    desX = -45;
    desY = -8;
    pros::delay(600);

    // turn to elevation and intake triball

    /*moveTurn = false;

    desOrientation = 270;
    pros::delay(500);*/

    intakeA.move(127);

    moveTurn = true;

    // go to middle of field

    // go back to starting pos and release triball
    desX = 0;
    desY = 0;
    pros::delay(1500);

    moveTurn = false;

    desOrientation = 50;
    pros::delay(800);
    
    moveTurn = true;

    desX = 2;
    desY = 3;
    pros::delay(1000);

    intakeA.move(-127);
    pros::delay(200);

    intakeA.move(0);

    // take matchload triball out

    moveTurn = true;

    wingR.set_value(true);

    for (int i = 0; i < 3; i++) {
        desX += 2;
        desY += 3;
        pros::delay(200);
    }

    // push elevation pole, preload, matchload triaball in goal
    desX = 25;
    desY = 40;

    pros::delay(500);

    wingR.set_value(false);

    pros::delay(500);

    // move to center of field
    desX = 0;
    desY = 0;
    pros::delay(800);

    // turn to right middle triball and intake
    moveTurn = false;

    desOrientation = 330;
    pros::delay(500);

    intakeA.move(127);

    moveTurn = true;

    desX = -50;
    desY = 30;
    pros::delay(1000);

    // spit out triball
    moveTurn = false;

    desOrientation = 60;
    pros::delay(500);

    intakeA.move(-127);

    pros::delay(500);

    // turn to middle back tribal and intake
    desOrientation = 345;
    pros::delay(500);

    intakeA.move(127);

    moveTurn = true;

    desX = -50;
    desY = 55;

    pros::delay(1200);

    // spit out triball
    moveTurn = false;

    desOrientation = 90;
    pros::delay(500);

    intakeA.move(-127);

    pros::delay(300);

    // push 3 middle triball across field
    intakeA.move(0);

    wingL.set_value(true);
    wingR.set_value(true);

    pros::delay(200);

    moveTurn = true;

    desX = 15;
    pros::delay(800);

    // touch pole
    desX = -60;
    desY = 25;
    pros::delay(1000);

    wingL.set_value(false);
    wingR.set_value(false);

    moveTurn = false;
    
    desOrientation = 180;
    pros::delay(800);
    
    moveTurn = true;
    desY -= 50;
    desX -= 10;
    pros::delay(1000);
}

// ##############################################################################################
// ##############################################################################################

inline void netSideRush() {
    turnMulti = 3;

    // push preload to goal with wing
    wingR.set_value(true);

    // move to centre centre triball (1)
    intakeA.move(-127);// unhook

    desX = -35;
    desY = 47;
    pros::delay(500);
    intakeA.move(127);
    wingR.set_value(false);
    pros::delay(1000);

    // turn to goal
    moveTurn = false;

    desOrientation = 90;
    pros::delay(800);

    wingL.set_value(true);

    // push (1) and centre right (2)
    turnMulti = 2;
    moveTurn = true;

    desX = 20;
    desY = 42;
    pros::delay(400);
    intakeA.move(-127);
    pros::delay(600);

    // move back turn to centre down (3)
    wingL.set_value(false);

    desX = 0;
    pros::delay(300);

    moveTurn = false;

    desOrientation = 210;
    pros::delay(500);

    // intake (3)
    intakeA.move(127);

    moveTurn = true;

    desX = -40;
    desY = 20;
    pros::delay(1500);

    // turn to goal
    moveTurn = false;

    desOrientation = 20;
    pros::delay(1000);

    // push (3)
    turnMulti = 4;
    moveTurn = true;

    desX = 20;
    desY = 40;
    pros::delay(500);
    intakeA.move(-127);
    pros::delay(700);

    // move back to start
    desX = 5;
    pros::delay(200);

    desX = -5;
    desY = -10;
    pros::delay(1500);

    // push out matchload (5)
    turnMulti = 1.5;
    moveTurn = false;

    desOrientation = 60;
    pros::delay(1000);

    intakeA.move(-127);
    wingR.set_value(true);

    moveTurn = true;

    desX = 15;
    desY = 5;
    pros::delay(1500);

    wingR.set_value(false);

    // push (4) (5) prelaod
    moveTurn = false;
    
    desOrientation = 250;
    pros::delay(1000);

    moveTurn = true;

    desX = 15;
    desY = 30;
    pros::delay(1000);
}

// ##############################################################################################
// ##############################################################################################

inline void matchloadRush() {
    turnMulti = 3;

    // push preload to goal with wing
    wingL.set_value(true);

    // move to centre centre triball (1)
    intakeA.move(-127); // unhook

    desX = 6;
    desY = 46.5;
    pros::delay(500);
    intakeA.move(127);
    wingL.set_value(false);
    pros::delay(1500);

    intakeA.move(0);

    // move back to starting position
    desX = -5;
    desY = 0;
    pros::delay(1500);

    // turn to goal and push preload
    moveTurn = false;

    desOrientation = 90;
    pros::delay(500);
    
    turnMulti = 2;
    moveTurn = true;

    desX = -15;
    desY = 0;
    pros::delay(1000);

    desX = -27;
    desY = 35;
    pros::delay(1000);

    // take out matchload
    desX = -20;
    desY = 0;
    pros::delay(1000);

    wingR.set_value(true);

    desX = -5;
    desY = -10;
    pros::delay(1000);

    moveTurn = false;

    desOrientation = 30;
    pros::delay(300);
    desOrientation = 95;
    pros::delay(1500);

    moveTurn = true;

    wingR.set_value(false);

    // push triballs and touch elevation pole
    desX = 25;
    desY = -8;
    pros::delay(1000);
    intakeA.move(-127);
    pros::delay(1000);
}