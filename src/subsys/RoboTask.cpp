#include "./subsysHeaders/RoboTask.hpp"

#include "./subsysHeaders/globals.hpp"
class TaskManager;


RoboTask::RoboTask(RoboTask *task) {
    this->finishedFlag = false;
    this->x = task->x;
    this->y = task->y;
    this->turnCompleted = false;
    this->reversed = task->reversed;
    this->armFront = task->armFront;
    this->armBack = task->armBack;
    this->timeDelayAfterFinished = task->timeDelayAfterFinished;
    this->totalOperations = 3;
}

RoboTask::~RoboTask(){}

RoboTask::RoboTask(float x, float y, bool reversed,  float armFront, float armBack, float timeDelayAfterFinished) {
    this->finishedFlag = false;
    this->x = x;
    this->y = y;
    this->turnCompleted = false;
    this->reversed = reversed;
    this->armFront = armFront;
    this->armBack = armBack;
    this->timeDelayAfterFinished = timeDelayAfterFinished;
    this->totalOperations = 3;
}

 void RoboTask::update() {
    /* This function is designed to work with PID to get to the target values,
        and update the finishedFlag according to reaching the target. */
    pros::lcd::set_text(4, std::to_string(armPosFront)  + " : " + std::to_string(armPosBack));
    pros::lcd::set_text(6, "Moving to X| "+ std::to_string(this->x) + " and Y| " + std::to_string(this->y));
    int operationsCompleted = 0;
    if(this->x >= 0 && this->y >= 0)
     { /* Task Being Implemented is Changing Current POS */
        move_to(this->x, this->y, this->reversed, &this->turnCompleted);
        if (posInRange(this->x, this->y) && turnCompleted )
        {
            setDrive(0,0);
            operationsCompleted++;
        }
    }
    else operationsCompleted++;
    //if() arm pos
//     if(this->armBack != armPosBack) {
//       setArmPosBack(this->armBack);
//       if (fabs(this->armBack - armPosBack) < 220) operationsCompleted++;
//   } else operationsCompleted++;
        operationsCompleted++;

      if(this->armFront != armPosFront) {
      setArmPosFront(this->armFront);
      if (fabs(this->armFront - armPosFront) < 220) operationsCompleted++;
  } else operationsCompleted++;
    pros::lcd::set_text(7,std::to_string(operationsCompleted)+" of " + std::to_string(this->totalOperations));


    if (operationsCompleted == this->totalOperations) {
        /* Delay time for task to finish */
        setDrive(0,0);
        setArmPosFront(armPosFront);
        setArmPosBack(armPosBack);
        pros::delay(timeDelayAfterFinished);
        finishedFlag = true;
    }
}
