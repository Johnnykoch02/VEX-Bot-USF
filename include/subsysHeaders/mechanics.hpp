#include "main.h"

//Driver
void setDriveMotors();

//Autonomous
void translate(int un, int vol); // Changing These
bool change_orientation(double theta);
bool cal();

/* *Needs intake and Lift Update* */

//Helpers
void setDrive();
void resetDriveEncoders();
double avgDriveEncoderValue();
