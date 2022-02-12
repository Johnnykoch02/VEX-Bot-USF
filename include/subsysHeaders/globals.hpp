#pragma once
#include "main.h"
#include "./subsysHeaders/TaskManager.hpp"
class TaskManager;
// Control Softwares
extern TaskManager task_manager;

//MOTORS
extern pros::Motor driveFrontLeft;
extern pros::Motor driveFrontRight;
extern pros::Motor driveBackLeft;
extern pros::Motor driveBackRight;
extern pros::Motor driveMiddleLeft;
extern pros::Motor driveMiddleRight;
extern pros::ADIEncoder leftEncoder;
extern pros::ADIEncoder rightEncoder;




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
extern float oldRoboMatrix[2][2];
extern int const ENCODERTICKCOUNT;
extern double getAngle();
extern double toAngle();

// extern int[] params(string params, int arg_num);
