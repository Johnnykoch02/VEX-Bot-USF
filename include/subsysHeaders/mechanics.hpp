#pragma once
// #include "main.h"
#include "./subsysHeaders/globals.hpp"

//Driver
void setDriveMotors();

//Autonomous
// Obstacle Avoidance
void move_to(float x, float y, bool reversed); // Changing These
void change_orientation(double theta);
void updateRoboMatrix();
bool cal();

/* *Needs intake and Lift Update* */

//Helpers
void setDrive(float leftPct, float rightPct);
void resetDriveEncoders();
double avgDriveEncoderValue();
void tare_encoders();
float avgLeftEncoders();
float avgRightEncoders();
float* resultant_vector();

bool posInRange(float x, float y);

void updatePower(float x, float y, bool reversed);
// Externs
