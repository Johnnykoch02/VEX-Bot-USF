// Control Softwares
#include "./subsysHeaders/globals.hpp"

TaskManager task_manager = TaskManager();
// Motors
pros::Motor driveFrontLeft(6, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveFrontRight(2, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackLeft(8, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackRight(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveMiddleLeft(0, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveMiddleRight(0, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

                            /*std::uint8_t iportTop, std::uint8_t iportBottom*/
// pros::ADIEncoder leftEncoder(0,0, false);
// pros::ADIEncoder rightEncoder(0,0, true);

// Sensors
pros:: Imu imu(12);
// Controllers
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//MUTEX
// pros::Mutex mutex;

// Global Variables
int const MAX_VOLTAGE = 12000;
int const MATRIX_LOCATION = 1;
int const ROBO_X = 0;
int const ROBO_Y = 1;
int const ticksPERFOOT = 360;

bool intakeState = false;
bool liftState = false;
float armPos = 0.0;

//K-Values for PID
float kp_pos = 3.0;
float ki_pos = 1.5;
float kd_pos = 0.25;
float kp_angle = 2.5;
float ki_angle = 5.0;
float kd_angle = 0.75;
float kp_arm;
float ki_arm;
float kd_arm;

float roboMatrix[2][2] = {
  {0.0, 0.0}, // Theta (qngle we are facing compared to the unit circle), second value is delta T.
  {0.0, 0.0} // Pos x Coordinate on plane, Pos y Coordinate on plane
};
float oldRoboMatrix[2][2] = {
  {0.0, 0.0}, // Theta (qngle we are facing compared to the unit circle), second value is delta T.
  {0.0, 0.0} // Pos x Coordinate on plane, Pos y Coordinate on plane
};
float timeMatrix[2] = {
    0.0, 0.0
};

float getAngle(){
  float theta = imu.get_heading();
  // if(theta>180) {
  //   theta = theta-360.0;
  // }//endif
  return theta;
}

float toAngle(float theta) {
  return (float)((int)theta%360);
}

