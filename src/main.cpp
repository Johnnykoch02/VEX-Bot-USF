#include "main.h"
// //
// // void test_func(){
// //   pros::lcd::set_text(1, "Button Pressed");
// //   pros::delay(1000);
// //   pros::lcd::set_text(1, "");
// // }
//



void initialize() {
  pros::lcd::initialize();
  pros::lcd::set_text(1,"LCD Initialided!");
  // pros::lcd::register_btn1_cb(test_func);
  driveFrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveFrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveBackLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  imu.tare();
  tare_encoders();
  pros::delay(1000);
}

void autonomous(void) {
  while (true)
  {
    pros::lcd::set_text(0, "Angle: ");
    pros::lcd::set_text(1, std::to_string(getAngle()));
  }

}



void opcontrol() {
  
  tare_encoders();
  while(true) {
    updateRoboMatrix();
    pros::lcd::set_text(0, "Matrix info| X:"+ std::to_string(roundf(roboMatrix[1][0])) + 
    "| Y:" +std::to_string(roundf(roboMatrix[1][0])) +
    "| Th:" + std::to_string(roundf(getAngle())) +
    "| DT:"+ std::to_string(roboMatrix[0][1]));
    //Driver Controller
    setDriveMotors();
    
    //Angler Control

    pros::delay(10);
  } //endwhile
}
