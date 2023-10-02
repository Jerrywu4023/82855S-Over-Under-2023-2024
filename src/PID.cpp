#include "DriveFunctions.cpp"
//Enable and Disable PID
bool enableDrivePID = true;

//Settings or Tuning for PID
double kP = 0.0; 
double kI = 0.0;
double kD = 0.0;

double turnkP = 0.0;
double turnkI = 0.0;
double turnkD = 0.0;

//Odom Settings input stuff
int desiredValue = 0;
int desiredTurn = 0;

int error; // Sensor Value - Desired Value <-- Positional Value / Delta X
int prevError = 0; // Position 20ms aago
int derivative; // Error - prevError <-- Speed
int totalError = 0; // TotalError = TotalError + Error

int turnError; // Sensor Value - Desired Turn Value 
int turnPrevError = 0;
int turnDerivative;
int turnTotalError = 0;

void drivePID(){
    while (enableDrivePID){

        // Get position of a motor on each side
        int leftMotorPosition = LF.get_position();
        int rightMotorPosition = RF.get_position();

        // Lateral Movement PID
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // Average of two sides
        int averagePosition = (leftMotorPosition + rightMotorPosition) / 2;

        // Proportional (P) for error
        error = averagePosition - desiredValue;

        // Derivative (D) for speed
        derivative = error - prevError;

        // Integral (I) for minor corrections
        totalError += error;

        // Turning Movement PID
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Difference of two sides
        int turnDifference = leftMotorPosition - rightMotorPosition;

        // Proportional (P)
        turnError = averagePosition - desiredValue;

        // Derivative (D)
        turnDerivative = turnError - turnPrevError;

        // Integral (I)
        turnTotalError += turnError;

        /* Controlling motors using power because there is no need to hard lock the velocity of the drive. 
        PID and Odometry will adjust the drive power accoridng to the orientatino fo the robot */
        double lateralMotorPower = (error * kP + derivative * kD + totalError * kI);
        double turningMotorPower = (turnError * turnkP + turnDerivative * turnkD + turnTotalError * turnkI);

        movePL (lateralMotorPower - turningMotorPower);
        movePR (lateralMotorPower + turningMotorPower);

        prevError = error;
        turnPrevError = turnError;
        pros::delay(20);
    }

}