#pragma once
#include "main.h"

using namespace std;
// Control Softwares
extern TaskManager task_manager;

//MOTORS
extern pros::Motor driveFrontLeft;
extern pros::Motor driveFrontRight;
extern pros::Motor driveBackLeft;
extern pros::Motor driveBackRight;
extern pros::Motor driveMiddleLeft;
extern pros::Motor driveMiddleRight;




//Sensors
extern pros::Imu imu;


//Controllers
extern pros::Controller controller;

//Misc
extern int const MAX_VOLTAGE;
extern int const MATRIX_LOCATION;
extern int const ROBO_X;
extern int const ROBO_Y;


// #define ANGLER_POT_VERTICAL 3000
extern float roboMatrix[2][2];
extern double getAngle();
extern double toAngle();
extern void go();

// extern int[] params(string params, int arg_num);
