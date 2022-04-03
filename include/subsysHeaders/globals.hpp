#pragma once
#include "main.h"
#include "./subsysHeaders/TaskManager.hpp"
#include "./subsysHeaders/GameObjectHandler.hpp"
class TaskManager;
// Control Softwares
extern TaskManager task_manager;
extern GameObjectHandler ObjHandler;
// extern 
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
extern pros::ADIDigitalOut pneumaticsLeft;
extern pros::ADIDigitalOut pneumaticsRight;
extern pros::ADIDigitalIn limitFront;
extern pros::Motor armFront;
extern pros::Motor armBack;
//Controllers
extern pros::Controller controller;

//Misc
extern int const MAX_VOLTAGE;
extern int const MATRIX_LOCATION;
extern int const ROBO_X;
extern int const ROBO_Y;
extern float const RADIUS;
extern float const PI;
extern bool tryingToStop;
extern float StraightVector[2];
extern float rLVector[2];
extern float rRVector[2];
extern float armErrorFront[2];
extern float armErrorBack[2];

// #define ANGLER_POT_VERTICAL 3000
extern float roboMatrix[2][2];
extern float oldRoboMatrix[2][2];
extern float timeMatrix[2];
extern float errorPower[2];
extern float powerDelta[2];

extern bool intakeState;
extern bool liftState;
extern float armPosFront;
extern float armPosBack;
extern int minArmPos;
extern int maxArmPos;
extern float const MAXARMPOS;

extern int const ticksPERINCH;
extern float getAngle();
extern float toAngle();
extern float min(float a, float b);
extern float DEG2RAD(float deg );
extern float RAD2DEG(float rad );

extern float get_dTheta(float tf, float ti);

extern float kp_pos;
extern float ki_pos;
extern float kd_pos;

extern float kp_angle;
extern float ki_angle;
extern float kd_angle;

extern float kp_arm;
extern float ki_arm;
extern float kd_arm;
// extern int[] params(string params, int arg_num);
