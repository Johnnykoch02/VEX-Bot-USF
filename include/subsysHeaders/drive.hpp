#include "main.h"

//Driver
void setDriveMotors();

//Autonomous
bool translate(int units, int voltage);
bool change_orientation(double theta);
bool cal();

//Helpers
void setDrive();
void resetDriveEncoders();
double avgDriveEncoderValue();
