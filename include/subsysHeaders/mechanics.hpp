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
void setDrive(float leftPct, int leftDir, float rightPct, int rightDir);
void resetDriveEncoders();
double avgDriveEncoderValue();
void tare_encoders();
float avgLeftEncoders();
float avgRightEncoders();
float* resultant_vector();

bool posInRange(float x, float y);

int getLeftPower(float x, float y);
int getRightPower(float x, float y);
int getLeftPowerTheta(float theta, float dtheta, int direction);
int getRightPowerTheta(float theta, float dtheta, int direction);
// Externs
