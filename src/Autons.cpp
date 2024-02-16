#include "DriverModes.cpp"

inline int autonNum;

inline void autoStart() {
	pros::Task Odom(odometry);
	pros::Task move(coordMove);
	pros::Task turning(turn);
	pros::Task out(PowerOutput);
	pros::delay(10);
}

inline void matchloadAvoid () {
    // push alliance triball to opponent goal
    turnMulti = 5;

    desX = 22;
    desY = -40;
    pros::delay(1200);

    // drive back to match loader
    turnMulti = 2;

    desX = 7;
    desY = -4;
    pros::delay(1200);

    // turn to match loader
    moveTurn = false;

    desOrientation = 330;
    pros::delay(500);

    // open wall
    wingR.set_value(true);
    pros::delay(500);

    // push triball out matchloader

    desOrientation = 240;
    pros::delay(1000);

    wingR.set_value(false);

    desOrientation = 290;
    pros::delay(800);

    moveTurn = true;

    intakeA.move(-127);

    desX -= 43;
    desY = 0;
    pros::delay(1500);

    /*wingL.set_value(true);

    moveTurn = false;

    desOrientation = 290;
    pros::delay(800);*/

    auton = false;

    moveL(0);
    moveR(0);
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
    // push alliance
    turnMulti = 4;
    intakeA.move(-127);

    desX = 40;
    desY = 25;
    pros::delay(1000);

    turnMulti = 3;
    intakeA.move(0);

    // move to matchlaod
    desX = 9;
    desY = 13;
    pros::delay(1200);

    wingL.set_value(true);

    // turn to shoot
    moveTurn = false;

    desOrientation = 342;

    pros::delay(1000);

    // matchload
    disableOdomControl = true;
    enableOdom = false;
    moveL(0);
    moveR(0);
    cataA.move(127);

    for (int i = 0; i < 14; i++) {
        pros::delay(2000);
    }

    imu1.reset();
	imu2.reset();
    pros::lcd::initialize();

    thetaReset = 340 * pi / 180;

    pros::delay(4000);

    disableOdomControl = false;
    enableOdom = true;

    autoStart();

    pros::delay(1000);

    wingL.set_value(false);

    cataA.move(0);

    // move across field
    desOrientation = 35;

    cataA.move(0);

    pros::delay(300);

    moveTurn = true;

    desX = -4;
    desY = -15;
    pros::delay(500);

    for (int i = 0; i < 3; i++) {
        desY -= 23;
        pros::delay(500);
    }

    pros::delay(500);

    // push right side
    wingL.set_value(false);
    wingR.set_value(false);

    moveTurn = false;

    desOrientation = 330;
    pros::delay(700);

    moveTurn = true;

    desX = 70;
    desY = -110;
    pros::delay(1200);

    /*desX = 0;
    desY = -90;
    pros::delay(1000);

    desX = 65;
    desY = -125;
    pros::delay(1000);*/

    wingL.set_value(false);
    wingR.set_value(false);

    desX = 15;
    desY = -70;
    pros::delay(500);

    desX = 20;
    desY = -60;
    pros::delay(300);

    moveTurn = false;

    desOrientation = 190;
    pros::delay(800);

    moveTurn = true;

    desX = 45;
    desY = -40;
    pros::delay(1200);

    // push middle 1
    moveTurn = false;

    desOrientation = 170;
    pros::delay(500);

    wingL.set_value(true);
    wingR.set_value(false);
    pros::delay(300);
    
    moveTurn = true;
    
    desX = 48;
    desY = -120;
    pros::delay(1300);

    wingL.set_value(false);
    wingR.set_value(false);

    turnMulti = 4;

    desX = 48;
    desY = -38;
    pros::delay(1000);

    moveTurn = false;

    desOrientation = 90;
    pros::delay(800);

    moveTurn = true;

    desX = 120;
    desY = -42;
    pros::delay(1000);

    // push middle 2
    turnMulti = 2.5;
    moveTurn = false;

    desOrientation = 220;
    pros::delay(500);

    wingL.set_value(true);
    wingR.set_value(true);
    pros::delay(200);
    
    moveTurn = true;
    
    desX = 65;
    desY = -115;
    pros::delay(1200);

    wingL.set_value(false);
    wingR.set_value(false);

    // push middle 3
    desX = 60;
    desY = -40;
    pros::delay(1000);

    moveTurn = false;

    desOrientation = 180;
    pros::delay(700);

    wingL.set_value(true);
    wingR.set_value(true);
    pros::delay(200);
    
    moveTurn = true;
    
    desX = 68;
    desY = -115;
    pros::delay(1200);

    wingL.set_value(false);
    wingR.set_value(false);

    // push left side
    turnMulti = 3;

    desY = -40;
    pros::delay(1000);

    moveTurn = false;

    desOrientation = 300;
    pros::delay(800);

    moveTurn = true;

    wingL.set_value(true);

    desX = 120;
    desY = -90;
    pros::delay(1500);

    moveTurn = false;

    wingL.set_value(false);

    desOrientation = 30;
    pros::delay(800);

    moveTurn = true;

    desX = 60;
    desY = -115;
    pros::delay(1500);

    desX = 110;
    desY = -80;
    pros::delay(600);
}

// ##############################################################################################
// ##############################################################################################

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

// ##############################################################################################
// ##############################################################################################

inline void netSideFull() {
    turnMulti = 2.5;

    intakeA.move(-127); // unhook

    desX = -48;
    desY = -8.2;
    pros::delay(200);

    intakeA.move(127);

    pros::delay(500);

    moveTurn = true;

    // go back to starting pos and release triball
    desX = 7;
    desY = 7;
    pros::delay(1200);

    moveTurn = false;

    desOrientation = 300;
    pros::delay(400);

    desOrientation = 60;
    pros::delay(600);

    intakeA.move(-127);
    pros::delay(100);

    // take matchload triball out
    wingR.set_value(true);

    pros::delay(300);

    desOrientation = 0;
    pros::delay(500);

    wingR.set_value(false);

    // push (4) (5) prelaod
    moveTurn = false;
    
    desOrientation = 250;
    pros::delay(800);

    moveTurn = true;
    
    // push elevation pole, preload, matchload triaball in goal
    desX = 20;
    desY = 45;
    pros::delay(1000);

    // move to center of field
    desX = 0;
    desY = 0;
    pros::delay(800);

    // turn to right middle triball and intake
    moveTurn = false;

    desOrientation = 300;
    pros::delay(700);

    intakeA.move(127);

    moveTurn = true;

    desX = -42;
    desY = 30;
    pros::delay(1300);

    // spit out triball
    moveTurn = false;

    desOrientation = 60;
    pros::delay(500);

    intakeA.move(-127);

    pros::delay(500);

    // turn to middle back tribal and intake
    desOrientation = 345;
    pros::delay(600);

    intakeA.move(127);

    moveTurn = true;

    desX = -40;
    desY = 55;
    pros::delay(900);

    // spit out triball
    moveTurn = false;

    desOrientation = 90;
    pros::delay(700);

    intakeA.move(-127);

    // push 3 middle triball across field
    wingL.set_value(true);
    wingR.set_value(true);

    pros::delay(200);

    moveTurn = true;

    desX = 20;
    desY = 48;
    pros::delay(800);

    wingL.set_value(false);

    desX = -20;
    pros::delay(500);

    // touch pole
    moveTurn = false;
    
    desOrientation = 350;
    pros::delay(1700);

    moveTurn = true;

    desX = -35;
    desY = 15;
    pros::delay(600);

    desY -= 40;
    desX -= 5;
    pros::delay(1000);

    auton = false;

    moveL(0);
    moveR(0);
}

// ##############################################################################################
// ##############################################################################################

inline void netSideRush() {
    turnMulti = 3;

    // push preload to goal with wing
    wingR.set_value(true);

    // move to centre centre triball (1)
    intakeA.move(-127);// unhook

    desX = -37;
    desY = 51;
    pros::delay(500);
    intakeA.move(127);
    wingR.set_value(false);
    pros::delay(1000);

    // turn to goal
    moveTurn = false;

    desOrientation = 85;
    pros::delay(700);

    wingL.set_value(true);
    wingR.set_value(true);

    // push (1) and centre right (2)
    turnMulti = 3;
    moveTurn = true;

    desX = 20;
    desY = 43;
    pros::delay(300);
    intakeA.move(-127);
    pros::delay(700);

    // move back turn to centre down (3)
    wingL.set_value(false);
    wingR.set_value(false);

    intakeA.move(0);

    desX = -50;
    pros::delay(300);

    moveTurn = false;

    desOrientation = 240;
    pros::delay(700);

    // intake (3)
    intakeA.move(127);

    moveTurn = true;

    desX = -42;
    desY = 20;
    pros::delay(900);

    /*// turn to goal
    moveTurn = false;

    desOrientation = 60;
    pros::delay(700);

    // push (3)
    turnMulti = 3;
    moveTurn = true;

    desX = 25;
    desY = 40;
    pros::delay(500);
    intakeA.move(-127);
    pros::delay(700);*/

    // extra
    moveTurn = false;
    desOrientation = 300;
    pros::delay(800);
    moveTurn = true;

    // move back to start
    /*desX = -15;
    pros::delay(500);

    moveTurn = false;

    desOrientation = 0;
    pros::delay(800);

    moveTurn = true;*/

    desX = -1;
    desY = 0;
    pros::delay(800);

    desX = -8;
    desY = -10;
    pros::delay(300);

    // release (3)
    intakeA.move(-127);
    pros::delay(300);

    moveTurn = false;

    // move to elevation (4)
    desOrientation = 0;
    pros::delay(200);

    desOrientation = 250;
    pros::delay(600);

    intakeA.move(127);

    moveTurn = true;
    desX = -45;
    desY = -8;
    pros::delay(1050);

    turnMulti += 0.3;

    desX = 13;
    desY = 4;
    pros::delay(1300);

    moveTurn = false;

    // return and release (4)
    desOrientation = 330;
    pros::delay(400);

    desOrientation = 60;
    pros::delay(500);


    intakeA.move(-127);

    wingR.set_value(true);

    pros::delay(200);

    desOrientation = 350;
    pros::delay(300);

    // push (4) (5) prelaod
    desOrientation = 220;
    pros::delay(600);

    wingR.set_value(false);

    moveTurn = true;

    desX = 30;
    desY = 35;
    pros::delay(1000);

    auton = false;

    movePL(127);
    movePR(100);
    pros::delay(300);

    movePL(-127);
    movePR(-80);
    pros::delay(1200);

    movePL(127);
    movePR(127);
    pros::delay(100);

    movePL(0);
    movePR(0);
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
    desY = 49;
    pros::delay(500);
    intakeA.move(127);
    wingL.set_value(false);
    pros::delay(1000);

    // move back to starting position
    desX = -6;
    desY = 4;
    pros::delay(1200);

    // turn to goal and push preload
    moveTurn = false;

    desOrientation = 90;
    pros::delay(500);
    
    turnMulti = 2;
    moveTurn = true;

    desX = -20;
    desY = 10;
    pros::delay(800);

    desX = -32;
    desY = 35;
    pros::delay(1000);

    // take out matchload
    desX = -20;
    desY = 5;
    pros::delay(500);

    desX = -14;
    desY = -7;
    pros::delay(1000);

    moveTurn = false;
    desOrientation = 130;
    pros::delay(300);

    wingR.set_value(true);
    pros::delay(200);

    desOrientation = 30;
    pros::delay(1000);
    wingR.set_value(false);

    desOrientation = 130;
    pros::delay(1500);

    moveTurn = true;
    //wingL.set_value(true);

    // push triballs and touch elevation pole
    desX = 28;
    desY = -7;
    pros::delay(500);
    intakeA.move(-127);
    pros::delay(2000);

    intakeA.move(0);
    /*moveTurn = false;
    desOrientation = 120;
    pros::delay(500);*/

    auton = false;
    moveL(0);
    moveR(0);
}

// ##############################################################################################
// ##############################################################################################

inline void driverSkills () {
    // push alliance
    turnMulti = 4;
    intakeA.move(-127);

    desX = 40;
    desY = 25;
    pros::delay(1000);

    turnMulti = 3;
    intakeA.move(0);

    // move to matchlaod
    desX = 9;
    desY = 13;
    pros::delay(1200);

    wingL.set_value(true);

    // turn to shoot
    moveTurn = false;

    desOrientation = 342;

    pros::delay(1000);

    // matchload
    cataA.move(127);

    for (int i = 0; i < 66; i++) {
        if (abs(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) > 100) break;
        pros::delay(500);
    }

    wingL.set_value(false);
    cataA.move(0);
    auton = false;
}

// ##############################################################################################
// ##############################################################################################

inline void matchloadRushElim() {
    turnMulti = 3;

    // push preload to goal with wing
    wingL.set_value(true);

    // move to centre centre triball (1)
    intakeA.move(-127); // unhook

    desX = 6;
    desY = 49;
    pros::delay(500);
    intakeA.move(127);
    wingL.set_value(false);
    pros::delay(1000);

    // move back to starting position
    desX = -5;
    desY = 5;
    pros::delay(1200);

    // turn to goal and push preload
    moveTurn = false;

    desOrientation = 90;
    pros::delay(500);
    
    turnMulti = 2;
    moveTurn = true;

    desX = -20;
    desY = 10;
    pros::delay(800);

    desX = -32;
    desY = 35;
    pros::delay(1000);

    // take out matchload
    desX = -20;
    desY = 5;
    pros::delay(500);

    desX = -14;
    desY = -7;
    pros::delay(1000);

    moveTurn = false;
    desOrientation = 130;
    pros::delay(300);

    wingR.set_value(true);
    pros::delay(200);

    desOrientation = 30;
    pros::delay(1000);
    wingR.set_value(false);

    desOrientation = 130;
    pros::delay(1500);

    moveTurn = true;
    //wingL.set_value(true);

    // push triballs and touch elevation pole
    desX = 28;
    desY = -4;
    pros::delay(500);
    intakeA.move(-127);
    pros::delay(2000);


    intakeA.move(0);

    desX = -20;
    desY = -1;
    pros::delay(1200);

    moveTurn = false;
    desOrientation = 100;
    pros::delay(600);

    auton = false;
    moveL(0);
    moveR(0);
}