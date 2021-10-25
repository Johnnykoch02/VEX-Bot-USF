#include "main.h"

//Driver
void setDriveMotors();

//Autonomous
void translate(int un, int vol);
bool change_orientation(double theta);
bool cal();

//Helpers
void setDrive();
void resetDriveEncoders();
double avgDriveEncoderValue();
