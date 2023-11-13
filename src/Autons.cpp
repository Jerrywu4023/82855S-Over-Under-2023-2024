#include "MotionAlg/PowerOutput.cpp"
#include "DriverModes.cpp"

inline void farside () {
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
    intakeExtend = !intakeExtend;
    intakeA.set_value(intakeExtend);

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