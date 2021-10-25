#include "main.h"

//MOTORS
extern pros:: Motor driveFrontLeft;
extern pros:: Motor driveFrontRight;
extern pros::Motor driveBackLeft;
extern pros::Motor driveBackRight;
extern pros::Motor driveMiddleLeft;
extern pros::Motor driveMiddleRight;
// extern pros::Mutex mutex;

//Sensors
extern pros:: Imu imu;


//Controllers
extern pros::Controller controller;

//Misc
// #define ANGLER_POT_VERTICAL 3000
extern int pos[2][2];
extern double getAngle();
extern double toAngle();
extern void go();