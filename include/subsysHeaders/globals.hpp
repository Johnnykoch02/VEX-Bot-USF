#include "main.h"

using namespace std;
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
extern const int MAX_VOLTAGE = 12000;
extern const int MATRIX_LOCATION = 1;
extern const int ROBO_X = 0;
extern const int ROBO_Y = 1;
// #define ANGLER_POT_VERTICAL 3000
extern int pos[2][2];
extern double getAngle();
extern double toAngle();
extern void go();

extern int[] params(string params, int arg_num);