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
  driveFrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  driveFrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  driveMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  // driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveBackLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  // driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  imu.tare();
  tare_encoders();
  pros::delay(1000);
}

void autonomous(void) {
  tare_encoders();
  while (true)
  {
    updateRoboMatrix();
    pros::lcd::set_text(0, "Matrix info| X:"+ std::to_string(roboMatrix[1][0]) + 
    "| Y:" +std::to_string(roboMatrix[1][1]));
    pros::lcd::set_text(1,  "| Th:" + std::to_string(roboMatrix[0][0]) +
    "| DT:"+ std::to_string(roboMatrix[0][1]));

    move_to(60, -60, false);
  }

}



void opcontrol() {
  
  tare_encoders();
  while(true) {
    updateRoboMatrix();
    pros::lcd::set_text(0, "Matrix info| X:"+ std::to_string(roboMatrix[1][0]) + 
    "| Y:" +std::to_string(roboMatrix[1][1]));
    pros::lcd::set_text(1,  "| Th:" + std::to_string(roboMatrix[0][0]) +
    "| DT:"+ std::to_string(roboMatrix[0][1]));
    //Driver Controller
    setDriveMotors();
    
    //Angler Control

    pros::delay(10);
  } //endwhile
}
