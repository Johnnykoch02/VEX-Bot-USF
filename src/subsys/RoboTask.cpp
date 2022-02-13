#include "./subsysHeaders/RoboTask.hpp"

#include "./subsysHeaders/globals.hpp"
class TaskManager;


RoboTask::RoboTask(RoboTask *task) {
    this->finishedFlag = false;
    this->x = x;
    this->y = y;
    this->intake = task->intake;
    this->lift = task->lift;
    this->arm = task->arm;
    int count = 0;
    if(this->x >= 0 && this->y >= 0) count++;
    if(this-> intake != intakeState) count++;
    if(this->lift != liftState) count++;
    if(this->arm != armPos) count++;
    this->totalOperations = count;
}

RoboTask::~RoboTask(){}

RoboTask::RoboTask(float x, float y, bool lift, bool intake, float arm) {
    this->finishedFlag = false;
    this->x = x;
    this->y = y;
    this->intake = intake;
    this->lift = lift;
    this->arm = arm;
    int count = 0;
    if(this->x >= 0 && this->y >= 0) count++;
    if(this-> intake != intakeState) count++;
    if(this->lift != liftState) count++;
    if(this->arm != armPos) count++;
    this->totalOperations = count;
}

 void RoboTask::update() {
    /* This function is designed to work with PID to get to the target values,
        and update the finishedFlag according to reaching the target. */
        int operationsCompleted = 0;
    if(this->x > 0 && this->y > 0)
     { /* Task Being Implemented is Changing Current POS */
        move_to(this->x, this->y);
        if (posInRange(x, y))
        {
            operationsCompleted++;
        }
    }
    //if() arm pos
    if(this-> intake == intakeState) operationsCompleted++;
    if(this->lift == liftState) operationsCompleted++;
    if(this->arm == armPos) operationsCompleted++;

    if (operationsCompleted == totalOperations) finishedFlag = true;

}
