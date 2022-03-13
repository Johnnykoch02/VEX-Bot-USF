#include "./subsysHeaders/RoboTask.hpp"

#include "./subsysHeaders/globals.hpp"
class TaskManager;


RoboTask::RoboTask(RoboTask *task) {
    this->finishedFlag = false;
    this->x = task->x;
    this->y = task->y;
    this->turnCompleted = false;
    this->reversed = task->reversed;
    this->intake = task->intake;
    this->lift = task->lift;
    this->arm = task->arm;
    this->timeDelayAfterFinished = task->timeDelayAfterFinished;
    this->totalOperations = 4;
}

RoboTask::~RoboTask(){}

RoboTask::RoboTask(float x, float y, bool reversed, bool lift, bool intake, float arm, float timeDelayAfterFinished) {
    this->finishedFlag = false;
    this->x = x;
    this->y = y;
    this->turnCompleted = false;
    this->reversed = reversed;
    this->intake = intake;
    this->lift = lift;
    this->arm = arm;
    this->timeDelayAfterFinished = timeDelayAfterFinished;
    this->totalOperations = 4;
}

 void RoboTask::update() {
    /* This function is designed to work with PID to get to the target values,
        and update the finishedFlag according to reaching the target. */
    pros::lcd::set_text(4, std::to_string(powerDelta[0])  + " : " + std::to_string(powerDelta[1]));
    pros::lcd::set_text(6, "Moving to X| "+ std::to_string(this->x) + " and Y| " + std::to_string(this->y));
    int operationsCompleted = 0;
    if(this->x >= 0 && this->y >= 0)
     { /* Task Being Implemented is Changing Current POS */
        move_to(this->x, this->y, this->reversed, &this->turnCompleted);
        if (posInRange(this->x, this->y))
        {
            setDrive(0,0);
            operationsCompleted++;
        }
    }
    else operationsCompleted++;
    //if() arm pos
    if(this->intake == intakeState) operationsCompleted++;
    if(this->lift == liftState) operationsCompleted++;
    else {
        liftState = !liftState;
        setPneumatics();
    }
    if(this->arm != armPos) {
      setArmPos(this->arm);
      if (fabs(this->arm - armPos) < 16) operationsCompleted++;
  } else operationsCompleted++;
    pros::lcd::set_text(7,std::to_string(operationsCompleted)+" of " + std::to_string(this->totalOperations));


    if (operationsCompleted == this->totalOperations) {
        /* Delay time for task to finish */
        // setDrive(-powerDelta[0],-powerDelta[1]);
        // pros::delay(50);
        // setDrive(0,0);
        pros::delay(timeDelayAfterFinished);
        finishedFlag = true;
    }
}
