#include "./subsysHeaders/RoboTask.hpp"

#include "./subsysHeaders/globals.hpp"
class TaskManager;


RoboTask::RoboTask(RoboTask *task) {
    this->x = task->x;
    this->y = task->y;
    this->intake = task->intake;
    this->lift = task->lift;
}

// RoboTask::RoboTask(RoboTask task) {
//     this->x = task.x;
//     this->y = task.y;
//     this->intake = task.intake;
//     this->lift = task.lift;
// }

RoboTask::RoboTask(float x, float y, bool lift, bool intake) {
    this->x = x;
    this->y = y;
    this->intake = intake;
    this->lift = lift;
}
void RoboTask::init() {

}

 void RoboTask::update() {
    /* This function is designed to work with PID to get to the target values,
        and update the finishedFlag according to reaching the target. */
    // this->finishedFlag = translate(x, y);
}
