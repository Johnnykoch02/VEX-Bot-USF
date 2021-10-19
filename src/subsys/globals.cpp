#include "main.h"

// Motors
pros::Motor driveFrontLeft(1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveFrontRight(8, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackLeft(2, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveBackRight(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveMiddleLeft(3, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveMiddleRight(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

// Sensors
pros:: Imu imu(12);
// Controllers
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//MUTEX
pros::Mutex mutex;

//MISC

int pos[2][2] = {
  {0, 0}, // Theta (qngle we are facing compared to the unit circle), second value is undefined.
  {0, 0} // Pos x Coordinate on plane, Pos y Coordinate on plane
};

double getAngle(){
  double theta = imu.get_heading();
  // if(theta>180) {
  //   theta = theta-360.0;
  // }//endif
  return theta; 
}

void updatePos() {
  pos[0][0] = getAngle();
  // pos[1][0] =
}
