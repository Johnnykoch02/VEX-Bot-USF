#include "main.h"
#include "RoboTask.hpp"
#include "PriorityQueue"

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

class TaskManager {
public:
    RoboTask *current_task = nullptr;
    PriorityQueue tasks();
    TaskManager();
    void addTask(RoboTask *task, string parameters);
    void run();


};
#endif