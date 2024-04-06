#include "Odometry\Odometry.cpp"

// Variables #####
// Function switches
inline bool auton = true;
inline bool moveTurn = true; // move robot on true, turn robot on false
inline bool disableOdomControl = false;

// Desired values
inline double desX;
inline double desY;
inline double desOrientation;

// Motor powers
inline double desDrive;
inline double desTurn;

// Coordinate movement variables
inline double Xdiff, Ydiff;
inline double distance, angle;

inline double turnMulti = 2.7;
inline double driveMulti = 2.5;
inline double pivotPower = 2.3;

inline double turnRestrict;


/**
 * @brief coordMove function
 * Calculate the drive power needed to move to a desird coordinate based on distance and direction
 * 
 */
inline void coordMove() {
    while (auton) {
        if (moveTurn) {
            Xdiff = desX - globalX; // distance needed to travel in x direction
			Ydiff = desY - globalY; // distance needed to travel in y direction

            // get distance and angle
			distance = sqrt(pow(Xdiff, 2) + pow(Ydiff, 2)) * driveMulti; // distance from desired locaion
			angle = atan2(Xdiff, Ydiff) * 180 / pi - heading; // get direction of deired location according to robot heading

            turnRestrict = fabs(distance) / 40;

            if (turnRestrict > 1) turnRestrict = 1;

            // keep angle within [-180, 180]
			while (angle > 180) angle -= 360; // keep angle less than 180
			while (angle < -180) angle += 360; // keep angle greater than -180

            // calculate drive and turn power based on distance and angle

			if (fabs(angle) < 90) { // drive fwd with angle
				desDrive = distance;
				desTurn = angle * turnMulti;
			} 
            
            else if (angle < 0) { // left back corner
				desDrive = -distance; // drive rev
				desTurn = (angle + 180) * turnMulti; // move in angle so back pointing to target
			} 

            else {
				desDrive = -distance; // drive rev
				desTurn = (angle - 180) * turnMulti; // move in angle so back pointing to target
			}

            desTurn *= turnRestrict;
        }

        pros::delay(5); // delay
    }
}

/**
 * @brief turn function
 * Calculate the drive power needed to turn to a desired heading
 * 
 */
inline void turn() {
    while (auton) {
        if (!moveTurn) {
            // Set no fwd/rev movement
            desDrive = 0;

            if (desOrientation < heading) { // Desired orientation is left of current heading in the 0 to 360 range
                
                if (heading - desOrientation < 180) { // Left turn closer, negative power
                    desTurn = (desOrientation - heading) * pivotPower;
                } 
                
                else { // Right turn closer, positive power by adding 360
                    desTurn = (desOrientation + 360 - heading) * pivotPower;
                }
            } 
            
            else { // Desired orientation is right of the current heading in the 0 to 360 range
                
                if (desOrientation - heading < 180) { // Right turn closer, positive power
                    desTurn = (desOrientation - heading) * pivotPower;
                } 
                
                else { // Left turn closer, negative power
                    desTurn = (desOrientation - 360 - heading) * pivotPower;
                }
            }
        }
        pros::delay(5);
    }
}