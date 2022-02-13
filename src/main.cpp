#include "main.h"
// //
// // void test_func(){
// //   pros::lcd::set_text(1, "Button Pressed");
// //   pros::delay(1000);
// //   pros::lcd::set_text(1, "");
// // }
//

bool calibrate() {
  imu.tare();
  cal();
  return true;

}



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
  

  while(true) {
    double left = driveFrontLeft.get_position() + driveBackLeft.get_position();
    double right = driveFrontRight.get_position() + driveBackRight.get_position();

    pros::lcd::set_text(0, "left: " + std::to_string(left));
    pros::lcd::set_text(1,"right: " + std::to_string(right));
    //Driver Controller
    setDriveMotors();

    //Angler Control

    pros::delay(10);
  } //endwhile
}
