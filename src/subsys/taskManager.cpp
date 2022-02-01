#include "main.h"

TaskManager::TaskManager() {}

void TaskManager::addTask(RoboTask *task, string parameters) {
    this->tasks.enqueue(task, 0);
}
void TaskManager::ClearAllTasks() {
    this->tasks.deque_all();
    delete this->current_task; //I think
    this->current_task = nullptr;
}

void TaskManager::run() {
    if (this->current_task != nullptr)
    { /* Update and chek our current task*/
        this->current_task->update();
    }
    else if (tasks.isEmpty() == false)
    { /* Obtain the next task*/
        this->current_task = tasks.deque();
    }
    else
    {/* Do Nothing?*/
    pros::lcd::print(3, "All Tasks Completed.");

    }
}
