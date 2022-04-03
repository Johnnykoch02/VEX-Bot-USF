// Control Softwares
#include "./subsysHeaders/globals.hpp"

TaskManager task_manager = TaskManager();
GameObjectHandler ObjHandler = GameObjectHandler();
// Motors
pros::Motor driveFrontLeft(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveFrontRight(8, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackLeft(3, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackRight(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveMiddleLeft(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveMiddleRight(9, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);


pros::Motor armFront(20, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor armBack(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

                            /*std::uint8_t iportTop, std::uint8_t iportBottom*/
// pros::ADIEncoder leftEncoder(0,0, false);
// pros::ADIEncoder rightEncoder(0,0, true);
pros::ADIDigitalIn limitFront('A');

// Sensors
pros:: Imu imu(5);

// Controllers
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//MUTEX
// pros::Mutex mutex;

// Global Variables
int const MAX_VOLTAGE = 12000;
int const MATRIX_LOCATION = 1;
int const ROBO_X = 0;
int const ROBO_Y = 1;
int const ticksPERINCH = 40;
float const RADIUS = 7.5; //#INCHES
/* These Vectors point in the direction of the Case wheel towards the center of the robot */
float StraightVector[2] = {0,0};
float rLVector[2] = {0,0};
float rRVector[2] = {0,0};
bool intakeState = false;
bool liftState = false;
float armPosFront = 0.0;
float armPosBack = 0.0;
int minArmPos = 0;
int maxArmPos = 5500;
bool tryingToStop = false;

float errorPower[2];
float armErrorFront[2];
float armErrorBack[2];
float powerDelta[2] = {0.1, 0.1};

//K-Values for PID
float kp_pos = (13/2);
float ki_pos = (31/5);
float kd_pos = 12;
float kp_angle = 1.2;
float ki_angle = 0.4;
float kd_angle = 1.0;//20.5;
float kp_arm = 82;
float ki_arm;
float kd_arm = 20;

float roboMatrix[2][2] = {
  {0.0, 0.0}, // Theta (qngle we are facing compared to the unit circle), second value is delta T.
  {130.0, 4.0} // Pos x Coordinate on plane, Pos y Coordinate on plane
};
float oldRoboMatrix[2][2] = {
  {0.0, 0.0}, // Theta (qngle we are facing compared to the unit circle), second value is delta T.
  {130.0, 4.0} // Pos x Coordinate on plane, Pos y Coordinate on plane
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
  // return round(fmod(((360 - theta) + 90), 360.0));
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
