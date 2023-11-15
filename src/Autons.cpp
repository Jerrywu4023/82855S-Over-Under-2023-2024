#include "MotionAlg/PowerOutput.cpp"
#include "DriverModes.cpp"

inline void farSide () {
    // push alliance triball to opponent goal
    desX = -20;
    desY = 30;
    pros::delay(2000);

    // drive back to match loader
    desX = -10;
    desY = 10;
    pros::delay(1000);

    // open wall
    wingR.set_value(true);

    // push triball out matchloader
    for (int i = 0; i < 5; i++) {
        desX -= 2;
        desY -= 1;
        pros::delay(200);
    }

    wingR.set_value(false);

    // turn to middle of opponent offense zone
    moveTurn = false;

    desOrientation = 20;
    pros::delay(500);

    // drive to middle of opponent offense zone
    moveTurn = true;

    desX = 10;
    desY = 40;
    pros::delay(2000);

    // turn to pipe and open wall
    moveTurn = false;

    desOrientation = 90;
    pros::delay(1000);

    wingR.set_value(true);
    wingL.set_value(true);

    // push triballs over pipe
    moveTurn = true;

    desX += 30;
    pros::delay(1500);

    wingL.set_value(false);
    wingR.set_value(false);

    // drive back
    desX -= 10;
    pros::delay(500);

    // open intake
    intakePistState = !intakePistState;
    intakeA.set_value(intakePistState);

    // turn to elevation pole
    moveTurn = false;

    desOrientation = 180;
    pros::delay(800);

    // touch elevation pole
    moveTurn = true;

    desX += 10;
    desY = 10;
    pros::delay(3000);
}

inline void closeSide () {
    globalX = 10;
    globalY = 15;

    // turn to matchloader
    moveTurn = false;

    desOrientation = 30;

    wingR.set_value(true);

    // push alliance triball and matchload to alliance goal
    moveTurn = true;

    desX = 10;
    desY = 30;
    pros::delay(2000);

    wingR.set_value(false);

    // move back to starting pos
    desX = 5;
    desY = 10;
    pros::delay(1000);

    // turn to elevation
    moveTurn = false;

    desOrientation = 270;
    pros::delay(800);

    // touch elevation pole
    intakePistState = !intakePistState;
    intakeA.set_value(intakePistState);

    desX = -10;
    desY = 5;
    pros::delay(2000);

    desX = -30;
    desY = 10;
    pros::delay(1000);
}

inline void soloAwp () {
    // push alliance triball into alliance goal
    desX = 20;
    desY = 30;
    pros::delay(2000);

    // move back to starting zone
    desX = -10; 
    desY = 10;
    pros::delay(1500);

    moveTurn = false;
    
    desOrientation = 270;

    // drive across field
    moveTurn = true;

    desX = -50;
    desY = 5;
    pros::delay(500);

    for (int i = 0; i < 5; i++) {
        desX -= 7;
        desY += 1;
        pros::delay(500);
    }

    // turn to get matchload
    moveTurn = false;

    desOrientation = 330;
    pros::delay(300);

    // grab matchload to other side of field
    wingL.set_value(true);

    desX = -50;
    desY = 20;

    pros::delay(500);

    wingL.set_value(false);

    desX = -90;
    desY = 20;

    pros::delay(1000);

    desX = -80;
    desY = 10;

    for (int i = 0; i < 10; i++) {
        desX += 7;
        pros::delay(300);
    }

    // open intake and touch elevation pole
    intakePistState = !intakePistState;
    intakeA.set_value(intakePistState);

    desX = -10;
    desY = 5;
    pros::delay(1000);

    desX = -30;
    desY = 10;
    pros::delay(1000);
}

inline void skills () {
    // move to matchlaod
    intakeA.set_value(true);

    desX = 5;
    desY = 10;
    pros::delay(500);

    // matchload
    cataL.move(127);
    cataR.move(127);

    pros::delay(40000);

    intakeA.set_value(false);

    // move across field
    moveTurn = false;

    desOrientation = -300;
    pros::delay(500);

    moveTurn = true;

    desX = 10;
    desY = -15;

    for (int i = 0; i < 10; i++) {
        desY -= 6.5;
        pros::delay(300);
    }

    pros::delay(500);

    // push right side
    moveTurn = false;

    desOrientation = 120;
    pros::delay(500);

    moveTurn = true;

    wingL.set_value(true);
    wingR.set_value(false);

    desX = 25;
    desY = -105;
    pros::delay(1500);

    wingL.set_value(false);
    wingR.set_value(false);

    desY = -50;
    pros::delay(1500);

    // push middle 1
    moveTurn = false;
    
    desOrientation = 170;
    pros::delay(500);
    
    moveTurn = true;

    wingL.set_value(true);
    wingR.set_value(true);
    
    desX = 50;
    desY = -95;
    pros::delay(1500);

    wingL.set_value(false);
    wingR.set_value(false);

    desX = 65;
    desY = -50;
    pros::delay(1500);

    // push middle 2
    moveTurn = false;
    
    desOrientation = 190;
    pros::delay(500);
    
    moveTurn = true;

    wingL.set_value(true);
    wingR.set_value(true);
    
    desX = 75;
    desY = -95;
    pros::delay(1500);

    wingL.set_value(false);
    wingR.set_value(false);

    desX = 95;
    desY = -50;
    pros::delay(1500);

    // push left side
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
    pros::delay(1000);
}