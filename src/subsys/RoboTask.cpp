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
    this->timeDelayAfterFinished = task->timeDelayAfterFinished;
    this->totalOperations = 3;
    this->var_changes = task->var_changes;
}

RoboTask::~RoboTask(){
    // delete this->x;
    // delete this->y;
}

RoboTask::RoboTask(float *x, float *y, bool reversed,  float armFront,  float timeDelayAfterFinished) {
    this->finishedFlag = false;
    this->x = x;
    this->y = y;
    this->turnCompleted = false;
    this->reversed = reversed;
    this->armFront = armFront;
    this->timeDelayAfterFinished = timeDelayAfterFinished;
    this->totalOperations = 2;
}

RoboTask::RoboTask(float *x, float *y, bool reversed,  float armFront,  float timeDelayAfterFinished,std::tuple<std::string, int> var_changes) {
    this->finishedFlag = false;
    this->x = x;
    this->y = y;
    this->turnCompleted = false;
    this->reversed = reversed;
    this->armFront = armFront;
    this->timeDelayAfterFinished = timeDelayAfterFinished;
    this->totalOperations = 2;
    this->var_changes = var_changes;
}

 void RoboTask::update() {
    /* This function is designed to work with PID to get to the target values,
        and update the finishedFlag according to reaching the target. */
    pros::lcd::set_text(4, std::to_string(armPosFront) );
    pros::lcd::set_text(6, "Moving to X| "+ std::to_string(*this->x) + " and Y| " + std::to_string(*this->y));
    int operationsCompleted = 0;
    if(*(this->x) >= 0 && *(this->y) >= 0)
     { /* Task Being Implemented is Changing Current POS */
        move_to(*(this->x), *(this->y), this->reversed, &this->turnCompleted);
        if (posInRange(*(this->x), *(this->y)) == true && turnCompleted )
        {
            setDrive(0,0);
    pros::lcd::set_text(6, "Finished moving to X| "+ std::to_string(*this->x) + " and Y| " + std::to_string(*this->y));

            operationsCompleted++;
        }
    }
    else operationsCompleted++;

    operationsCompleted++;
    if(this->armFront != armPosFront) {
        setArmPos(this->armFront);
      if (fabs(this->armFront - armPosFront) < 220) operationsCompleted++;
  } else operationsCompleted++;
    pros::lcd::set_text(7,std::to_string(operationsCompleted)+" of " + std::to_string(this->totalOperations));


    if (operationsCompleted >= this->totalOperations) {
        /* Delay time for task to finish */
        setDrive(0,0);
        setArmPos(armPosFront);
        // setArmPosBack(armPosBack);
        pros::delay(timeDelayAfterFinished);
        finishedFlag = true;
    }
}

 void RoboTask::init() {
   if(get<0>(this->var_changes) == "") {
       //null string
   }
   else if (get<0>(this->var_changes) == "voltage") {
       CURRENT_VOLTAGE = get<1>(this->var_changes);
   }
 }