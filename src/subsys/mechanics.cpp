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

void change_orientation(float theta) {
  float dtheta = getAngle()-theta;
  int direction = 0;
  if (fabs(dtheta)< 180.0) {
    direction = 1 * (fabs(dtheta)/dtheta);
  }
  else {
    direction = -1 * (fabs(dtheta)/dtheta);
  }

    
    setDrive(getLeftPowerTheta(theta, dtheta, direction),-1*direction,getRightPowerTheta(theta, dtheta, direction), direction); // CHANGE THIS TO WORK DIRECTLY WITH PID
    pros::delay(10);

}

void updateRoboMatrix() {
  for(int i = 0; i < 2; i++) { for(int j = 0; j < 2; j++) {
      /*Update old Robo Matrix with the Current*/
      oldRoboMatrix[i][j]= roboMatrix[i][j];
    }
  }
    /* Update Time Values */
    timeMatrix[1] = timeMatrix[0];
    timeMatrix[0] = pros::millis() / 1000; 

    /* Update Robot Matrix */
    roboMatrix[0][0] = getAngle(); // ANGLE

    rRVector[0] = RADIUS * cos(DEG2RAD(roboMatrix[0][0]+90));
    rRVector[1] = RADIUS * sin(DEG2RAD(roboMatrix[0][0]+90));
    rLVector[0] = RADIUS * cos(DEG2RAD(roboMatrix[0][0]-90));
    rLVector[1] = RADIUS * sin(DEG2RAD(roboMatrix[0][0]-90));
    float *resultantVector = resultant_vector();
    roboMatrix[0][1] = timeMatrix[0] - timeMatrix[1]; // DT
    roboMatrix[MATRIX_LOCATION][ROBO_X] = roboMatrix[MATRIX_LOCATION][ROBO_X] + resultantVector[0]; //X POS // IDK the math
    roboMatrix[MATRIX_LOCATION][ROBO_Y] = roboMatrix[MATRIX_LOCATION][ROBO_Y] + resultantVector[1]; // Y POS

  delete[] resultantVector;
  
}

float* resultant_vector() {
  float *resultantVector = new float[2];
  /* Displacement divided by our radius vectors magnitude */
  float scaleLeftSide = (avgLeftEncoders() / ticksPERINCH) / RADIUS; 
  float scaleRightSide = (avgRightEncoders() / ticksPERINCH) / RADIUS;
  /* Tare encoder Values RIGHT after pilling their values */
  tare_encoders();
  /* Gets the rotational vector from the rotation matrix */
  float dthetaRight = DEG2RAD(roboMatrix[0][0] + 30);
  float dthetaLeft = DEG2RAD(roboMatrix[0][0] -30);
  float rightVec[2] = {scaleRightSide * (rRVector[0] * cos(dthetaRight) - rRVector[1] * sin(dthetaRight)) , 
                        scaleRightSide * (rRVector[0] * sin(dthetaRight) + rRVector[1] * cos(dthetaRight))
                      };
  float leftVec[2] = {scaleLeftSide * (rLVector[0] * cos(dthetaLeft) - rLVector[1] * sin(dthetaLeft)) , 
                        scaleLeftSide * (rLVector[0] * sin(dthetaLeft) + rLVector[1] * cos(dthetaLeft))
                      };            
  /* Populate the resultant vector  */
  resultantVector[0] = (rightVec[0] + leftVec[0]) / 2;
  resultantVector[1] = (rightVec[1] + leftVec[1]) / 2;

  return resultantVector;
}

void tare_encoders() {
  /* Fix for the actual encoders*/
  int a = driveFrontLeft.tare_position();
  int b = driveFrontRight.tare_position();
  int c = driveBackLeft.tare_position();
  int d = driveBackRight.tare_position();
  if (a + b + c + d != 4)
  {
    pros::lcd::set_text(4, "Something went wrong.");
  }
}

float avgLeftEncoders() {
  float a = driveFrontLeft.get_position();
  float b = driveBackLeft.get_position();
  return (a+b)/2;
}

float avgRightEncoders() {
  float a = driveBackRight.get_position();
  float b = driveFrontRight.get_position();
  return (a+b)/2;
}

int getLeftPower(float x, float y) {
  float dx = x - roboMatrix[1][0];
  float dy = y - roboMatrix[1][1];
  float displacement = sqrt(dx*dx+dy*dy);

  return 100;
}

int getRightPower(float x, float y) {
  return 100; 
}

int getLeftPowerTheta(float theta, float dtheta, int direction) {
  if (direction > 0) 
  {

  }

  else
  {

  }
  return 100;
}
int getRightPowerTheta(float theta, float dtheta, int direction) {
  return 100;
}

bool posInRange(float x, float y) {
  return sqrt(
      (roboMatrix[1][0] - x)* (roboMatrix[1][0] - x) + //DX^2
      (roboMatrix[1][1] - y) * (roboMatrix[1][1] - y) //DY^2
    )
    < kd_pos; //POS DIFFERENTIAL
}