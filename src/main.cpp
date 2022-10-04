#include "main.h"
#include <tuple>
#include <string>
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
float vals[7][2] = {
    {130,42.3}, //0
    {130,42}, //1
    {130,30}, //2
    {100,54}, //3
    {135,10}, //4
    {-1,-1},
    {130.0, 4.0}
  };
void action_swiper() {
  // SCHEDULING 
  task_manager.addTask(new RoboTask(&vals[0][0], &vals[0][1], false, maxArmPos/12, 0));
  task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], true, maxArmPos/1.5, 0 ));
  task_manager.addTask(new RoboTask(&vals[2][0], &vals[2][1], true, maxArmPos, 0));//, std::tuple<std::string, int>("voltage", MAX_VOLTAGE/2)));
  task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], true, maxArmPos/2, 0));//, std::tuple<std::string, int>("voltage", MAX_VOLTAGE/2)));
  task_manager.addTask(new RoboTask(&vals[6][0], &vals[6][1], true, maxArmPos/2, 0));//, std::tuple<std::string, int>("voltage", MAX_VOLTAGE/2)));  
  // task_manager.addTask(new RoboTask(&vals[3][0], &vals[3][1], false,  maxArmPos/2, 0));
  // task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], false, maxArmPos/5, 0));
  // task_manager.addTask(new RoboTask(&vals[4][0], &vals[4][1], true, maxArmPos/6, 0));
  // task_manager.addTask(new RoboTask(&roboMatrix[1][0], &roboMatrix[1][1], false, maxArmPos/6, 0));


}

void test_arm() {
  task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], false, armPosFront, 2000));
  task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], false, maxArmPos/10, 2000));
  task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], false, maxArmPos, 2000));
  task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], false, maxArmPos/1.5, 2000));
  task_manager.addTask(new RoboTask(&vals[5][0], &vals[5][1], false, minArmPos, 2000));

}
void autonomous(void) {
  tare_encoders();
  updateRoboMatrix();
  action_swiper();
  // test_arm();
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
  //   driveFrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  // driveFrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  // driveMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  // driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  // driveBackLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  // driveMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
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
