#include "main.h"

// Helper Functions
void setDrive(int leftPct, int leftDir,int rightPct, int rightDir) {
  int left = (int) ((leftPct/100) * leftDir * MAX_VOLTAGE);
  int right = (int) ((leftPct/100) * leftDir * MAX_VOLTAGE);
  driveFrontLeft.move_voltage(left);
  driveFrontRight.move_voltage(right);
  driveBackLeft.move_voltage(left);
  driveBackRight.move_voltage(right);
  driveMiddleLeft.move_voltage(left);
  driveMiddleRight.move_voltage(right);
}

void resetDriveEncoders() {
  // Resets encoders
  driveFrontLeft.tare_position();
  driveFrontRight.tare_position();
}

double avgDriveEncoderValue() {
  return fabs(driveFrontLeft.get_position()) +
            fabs(driveFrontRight.get_position())
            /2;
}

// Driver Control Functions

void setDriveMotors() {

  int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if (abs(leftJoystick) < 5) leftJoystick = 0;
  if (abs(rightJoystick)<5) rightJoystick = 0;
  setDrive(leftJoystick, rightJoystick);

}

// Autonomous

bool translate(int units, int voltage) {
  int units = un;
  int voltage = vol;
  // mutex.take(20000);
  int direction = abs(units)/units;
  // Reset motor encoders
  resetDriveEncoders();
  // Drive foward until units are reached
  while(avgDriveEncoderValue() < abs(units)) {
    setDrive(voltage*direction, voltage*direction);
    pros::delay(10);
  }
  // Brake
  setDrive(-10*direction, -10*direction);
  pros::delay(50);
  // Set drive back to neutral
  return true;
}



bool change_orientation(double theta) {
  // mutex.take(20000);
  float dtheta = getAngle()-theta;
  int direction = 0;
  if (fabs(dtheta)< 180.0) {
    direction = 1 * (fabs(dtheta)/dtheta);
  }
  else {
    direction = -1 * (fabs(dtheta)/dtheta);
  }

    while(fabs(getAngle()-theta) > 5.0) {
      setDrive(-50*direction,50*direction);
      pros::delay(10);
    }//ccw
    setDrive(10*direction,-10*direction);
    pros::delay(50);
  // mutex.give();
  return true;
}

bool cal() {
  driveFrontLeft = 35;
  driveFrontRight = -35;
  driveBackLeft = 35;
  driveBackRight = -35;
  driveMiddleLeft = 35;
  driveMiddleRight = -35;
  pros::delay(100);
  driveFrontLeft = -35;
  driveFrontRight = 35;
  driveBackLeft = -35;
  driveBackRight = 35;
  driveMiddleLeft = -35;
  driveMiddleRight = 35;
pros::delay(1000);
  return true;

}
