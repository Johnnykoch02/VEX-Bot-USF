#pragma once
// #include "main.h"
#include "./subsysHeaders/globals.hpp"

//Driver
void setDriveMotors();

//Autonomous
// Obstacle Avoidance
void translate(int x, int y); // Changing These
void change_orientation(double theta);
void updateRoboMatrix();
bool cal();

/* *Needs intake and Lift Update* */

//Helpers
void setDrive();
void resetDriveEncoders();
double avgDriveEncoderValue();


// Externs
