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
  imu.tare();
}


void opcontrol() {

  while(true) {
    pros::lcd::set_text(0, "Angle: ");
    pros::lcd::set_text(1, std::to_string(getAngle()));
    //Driver Controller
    setDriveMotors();

    //Angler Control

    pros::delay(10);
  } //endwhile
}


void go() {
  translate(1000,100);

change_orientation(90);
translate(1000,100);

change_orientation(180);
translate(1000,100);

change_orientation(270);
translate(1000,100);

change_orientation(0);
}

void autonomous() {

// pros::Task task_1(setDrive, 300);
// pros::Task task_2(change_orientation, 180);

  pros::delay(2000);
  go();

while(true){  
  // mutex.take(10000);
  pros::lcd::set_text(0, "Angle: ");
  pros::lcd::set_text(1, std::to_string(getAngle()));

}
}

