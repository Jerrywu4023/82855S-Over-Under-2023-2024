// Variables ##############################
// odom activate
inline bool enableOdom = true;

// tracking wheel dist to center
inline double Sl = 0;
inline double Ss = 0;

// tracking wheel diameters (inches)
inline double wheelL = 2.75;
inline double wheelR = 2.75;

// encoder values (centi degrees)
inline int totalL = 0;
inline int totalS = 0;

// actual total distance (inches)
inline double currL = 0;
inline double currS = 0;

// previous total distance (inches)
inline double prevL = 0;
inline double prevS = 0;

// tracking dist change (inches)
inline double deltL = 0;
inline double deltS = 0;

// angles (radians)
inline double thetaReset = 0; // inital starting angle
inline double deltTheta; // change in angle
inline double theta1 = 0; // abs orientation
inline double theta0 = 0; // previous abs orientation
inline double thetaMean = 0; // avg orientation, angle for local offset

// local offset
inline double deltX;
inline double deltY;

// global offset
inline double currDeltX;
inline double currDeltY;

// polar conversion of offset var
inline double offTheta; // rad angle of offset
inline double offRadius; // magnitude of offset vector

// Global position
inline double globalX = 0; // x coord
inline double globalY = 0; // y coord
inline double heading; // robot heading in degrees (0 - 359)