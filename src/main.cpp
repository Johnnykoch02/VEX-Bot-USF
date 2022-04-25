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
  driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  driveBackLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  armLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  armRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  imu.tare();
  tare_encoders();
  pros::delay(1000);
}

void autonomous(void) {
  tare_encoders();
  updateRoboMatrix();
                //#of pairs, [x,y]
  float task_vals[3][2] = {
                        {130, 390.0},
                          {130,4},
                          {130,4}
                          };

  // SCHEDULING 
  task_manager.addTask(new RoboTask(&task_vals[0][0], &task_vals[0][1], false, armPosFront, 100 ));
  task_manager.addTask(new RoboTask(&task_vals[1][0], &task_vals[1][1], false, armPosFront, 100 ));
  task_manager.addTask(new RoboTask(&task_vals[2][0], &task_vals[2][1], false, armPosFront, 100));
  while (true)
  {
    updateRoboMatrix();
    task_manager.run();
    pros::lcd::set_text(0, "Matrix info| X:"+ std::to_string(roboMatrix[1][0]) + 
    "| Y:" +std::to_string(roboMatrix[1][1]));
    pros::lcd::set_text(1,  "| Th:" + std::to_string(roboMatrix[0][0]) +
    "| DT:"+ std::to_string(roboMatrix[0][1]));
    pros::lcd::set_text(2, "Arm pos:" + to_string(armPosFront));
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


    pros::lcd::set_text(5,  std::to_string(armPosBack) + ": :" + std::to_string(armPosFront));
    //Driver Controller
    setController();
    
    //Angler Control

    pros::delay(10);
  } //endwhile
}
