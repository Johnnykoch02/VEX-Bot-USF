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

float toAngle(float theta) {
  return (float)((int)theta%360);
}


int[] params(string params, int arg_num) {
  int returnValue[arg_num];
  int currentIndex = 0;
  string curr = "";
  /* Loop over String, append to curr, then append to array based on comma delimiter */
  for (int i = 0; i < params.length(); i++) {
    /* Primary Seperator: checks first */
    if (char_traits::eq(params[i], ',')) {
      returnValue[currentIndex] = (int) curr;
      currentIndex++;
      curr = "";
    }
    else {
      curr+= params[i];
    }
  }
  /* Is there an item we havent added? */
  if (currentIndex < arg_num) {
     returnValue[currentIndex] = (int) curr;
  }

  return returnValue;
  
 }


//GO

void go() {
//   translate(1000,100); BOX

  int x[] = {100,100};
  pros::Task task{[=] {
          pros::lcd::set_text(4, "In Task One");
            translate(1000,100);
    }};
  pros::Task task_2{[=] {
            pros::lcd::set_text(4, "In Task Two");
            change_orientation(180);
            pros::lcd::set_text(4, "Done with task Two");
    }};

  // pros::Task::task_create(change_orientation(int),toAngle(getAngle()+180), pros::TASK_PRIO_DEFAULT,pros::TASK_STACK_DEPTH_DEFAULT, "Test Task");
  // pros::Task::task_create(translate(int)(int),{1000,100}, pros::TASK_PRIO_DEFAULT,pros::TASK_STACK_DEPTH_DEFAULT, "Test Task");
  // pros::Task::::task_create(change_orientation(int),toAngle(getAngle()+180), pros::TASK_PRIO_DEFAULT,pros::TASK_STACK_DEPTH_DEFAULT, "Test Task");
  // pros::Task::task_create(translate(int)(int),{1000,100}, pros::TASK_PRIO_DEFAULT,pros::TASK_STACK_DEPTH_DEFAULT, "Test Task");
  // pros::Task::::task_create(change_orientation(int),toAngle(getAngle()+180), pros::TASK_PRIO_DEFAULT,pros::TASK_STACK_DEPTH_DEFAULT, "Test Task");
  // pros::Task::task_create(translate(int)(int),{1000,100}, pros::TASK_PRIO_DEFAULT,pros::TASK_STACK_DEPTH_DEFAULT, "Test Task");
  // pros::Task::::task_create(change_orientation(int),toAngle(getAngle()+180), pros::TASK_PRIO_DEFAULT,pros::TASK_STACK_DEPTH_DEFAULT, "Test Task");

// change_orientation(90);
// translate(1000,100);

// change_orientation(180);
// translate(1000,100);

// change_orientation(270);
// translate(1000,100);

// change_orientation(0); ENDBOX

}
