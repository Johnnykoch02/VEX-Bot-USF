#include "main.h"

TaskManager::TaskManager() {}

void TaskManager::addTask(RoboTask *task, string parameters) {

}
void TaskManager::ClearAllTasks() {
    tasks.deque_all();
    delete this->current_task; //I think
    this->current_task = nullptr;  
}

void TaskManager::run() {
    if (this->current_task != nullptr) 
    { /* Update and chek our current task*/

    }
    else if (this->tasks.isEmpty() == false) 
    { /* Obtain the next task*/
        this->current_task = tasks.deque();
    }
}