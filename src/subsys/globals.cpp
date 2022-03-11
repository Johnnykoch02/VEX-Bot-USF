// Control Softwares
#include "./subsysHeaders/globals.hpp"

TaskManager task_manager = TaskManager();
// Motors
pros::Motor driveFrontLeft(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveFrontRight(2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackLeft(8, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackRight(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);


pros::Motor driveMiddleLeft(0, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveMiddleRight(0, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

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
int const MAX_VOLTAGE = 120000;
int const MATRIX_LOCATION = 1;
int const ROBO_X = 0;
int const ROBO_Y = 1;
int const ticksPERINCH = 120;
float const RADIUS = 7.5; //#INCHES
/* These Vectors point in the direction of the Case wheel towards the center of the robot */
float StraightVector[2] = {0,0};
float rLVector[2] = {0,0};
float rRVector[2] = {0,0};
bool intakeState = false;
bool liftState = false;
float armPos = 0.0;

float errorPower[2];
float powerDelta[2] = {0.1, 0.1};

//K-Values for PID
float kp_pos = (7/2);
float ki_pos = (12/5);
float kd_pos = 8;

float kp_angle = 14.0;
float ki_angle = 1.5;
float kd_angle = 0.8 ;//20.5;
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

float const PI =  3.14159;

float DEG2RAD( const float deg )
{
	return deg * PI/180;
}
float RAD2DEG( const float rad )
{
	return rad * 180/PI;
}

float getAngle(){
  float theta = imu.get_heading();
  return fmod(((360 - theta) + 90), 360.0);
}

float toAngle(float theta) {
  return (float)((int)theta%360);
}

float get_dTheta(float tf, float ti) {
    float positiveDTheta = fmod((tf+360)-ti, 360.0);
    float negativeDTheta = -360 + positiveDTheta;
    
    if (fabs(positiveDTheta) <= fabs(negativeDTheta))
    return positiveDTheta;
    else return negativeDTheta;

}


float min(float a, float b) {
  if (a<=b) return a;
  else return b;
}