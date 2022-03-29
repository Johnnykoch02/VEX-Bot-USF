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
  armFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  armBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  imu.tare();
  tare_encoders();
  pros::delay(1000);
}

void autonomous(void) {
  tare_encoders();
  updateRoboMatrix();

  
  //   task_manager.addTask(new RoboTask(-1,-1, false, maxArmPos,  0, 500));
  // task_manager.addTask(new RoboTask(127.0, 24, false, 0,  0, 100));
    // task_manager.addTask(new RoboTask(-1,-1, true, 2*maxArmPos/3,  0, 1000));
  task_manager.addTask(new RoboTask(127-4.53,24+8.84, true, 0,  0, 100));
    // task_manager.addTask(new RoboTask(-1, -1, true, 2*maxArmPos/4,  maxArmPos/3, 100));
  // task_manager.addTask(new RoboTask(127-15.8,24+31.4, true, 2*maxArmPos/3,  maxArmPos, 500));
  // task_manager.addTask(new RoboTask(-1,-1, true, maxArmPos/5,  maxArmPos/4, 500));
  // task_manager.addTask(new RoboTask(123,106, true, maxArmPos/5,  maxArmPos/4, 100)); 
  // task_manager.addTask(new RoboTask(120,126.5, false, 0, 0, 100)); 
  // task_manager.addTask(new RoboTask(65.5,128.5, false, maxArmPos/5,  maxArmPos/4, 100)); 
    // task_manager.addTask(new RoboTask(125,119, true, maxArmPos/4,  maxArmPos/3, 100)); 


  // task_manager.addTask(new RoboTask(-1, -1, false, minArmPos, minArmPos, 1000));

  bool t = false;
  
  while (true)
  {
    updateRoboMatrix();
    task_manager.run();
    pros::lcd::set_text(0, "Matrix info| X:"+ std::to_string(roboMatrix[1][0]) + 
    "| Y:" +std::to_string(roboMatrix[1][1]));
    pros::lcd::set_text(1,  "| Th:" + std::to_string(roboMatrix[0][0]) +
    "| DT:"+ std::to_string(roboMatrix[0][1]));
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
