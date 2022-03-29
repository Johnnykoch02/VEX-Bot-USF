#pragma once
// #include "main.h"
#include "./subsysHeaders/globals.hpp"

//Driver
void setController();

//Autonomous
// Obstacle Avoidance
void move_to(float x, float y, bool reversed,  bool *turnCompleted); // Changing These
void change_orientation(float x, float y, bool reversed, bool *turnCompleted);
void updateRoboMatrix();
bool cal();

/* *Needs intake and Lift Update* */

//Helpers
void setDrive(float leftPct, float rightPct);
void setArmPosFront(float targetPose);
void setArmPosBack(float targetPose);
void resetDriveEncoders();
double avgDriveEncoderValue();
void tare_encoders();
float avgLeftEncoders();
float avgRightEncoders();
float* resultant_vector();

bool posInRange(float x, float y);

void updatePower(float x, float y, bool reversed,  bool *turnCompleted);
// Externs
