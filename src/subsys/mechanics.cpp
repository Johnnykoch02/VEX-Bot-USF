#include "./subsysHeaders/mechanics.hpp"
#include "./subsysHeaders/globals.hpp"
// Helper Functions
void setDrive(int leftPct, int leftDir,int rightPct, int rightDir) {
  int left = (int) ((leftPct/100) * leftDir * MAX_VOLTAGE);
  int right = (int) ((leftPct/100) * leftDir * MAX_VOLTAGE);
  driveFrontLeft.move_voltage(left);
  driveFrontRight.move_voltage(right);
  driveBackLeft.move_voltage(left);
  driveBackRight.move_voltage(right);
  // driveMiddleLeft.move_voltage(left);
  // driveMiddleRight.move_voltage(right);
}


// Driver Control Functions

void setDriveMotors() {

  int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if (abs(leftJoystick) < 5) leftJoystick = 0;
  if (abs(rightJoystick)<5) rightJoystick = 0;
  setDrive(abs(leftJoystick), abs(leftJoystick)/leftJoystick , rightJoystick, abs(rightJoystick)/rightJoystick);

}

// Autonomous

void change_orientation(double theta, int power) {
  float dtheta = getAngle()-theta;
  int direction = 0;
  if (fabs(dtheta)< 180.0) {
    direction = 1 * (fabs(dtheta)/dtheta);
  }
  else {
    direction = -1 * (fabs(dtheta)/dtheta);
  }

    while(fabs(getAngle()-theta) > 1.2) {
      setDrive(power,-1*direction,power, direction);
      pros::delay(10);
    }//ccw
     setDrive(power,-1*direction,power, direction);
    pros::delay(10);

}

void updateRoboMatrix() {
  for(int i = 0; i < 2; i++) { for(int j = 0; j < 2; j++) {
      /*Update old Robo Matrix with the Current*/
      oldRoboMatrix[i][j]= roboMatrix[i][j];
    }
  }

  roboMatrix[0][0] = getAngle();
  // int leftEncoderRead = (int) leftEncoder.get();
  // int rightEncoderRead = (int) rightEncoder.get();
  // leftEncoder.reset();
  // rightEncoder.reset();

}
