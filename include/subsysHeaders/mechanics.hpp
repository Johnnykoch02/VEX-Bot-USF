#pragma once
// #include "main.h"
#include "./subsysHeaders/globals.hpp"

//Driver
void setDriveMotors();

//Autonomous
// Obstacle Avoidance
void move_to(float x, float y); // Changing These
void change_orientation(double theta);
void updateRoboMatrix();
bool cal();

/* *Needs intake and Lift Update* */

//Helpers
void setDrive();
void resetDriveEncoders();
double avgDriveEncoderValue();
void tare_encoders();

bool posInRange(float x, float y);

int getLeftPower();
int getRightPower();
// Externs
