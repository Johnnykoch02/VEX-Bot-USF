#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "main.h"
#include "RoboTask.hpp"
#include "PriorityQueue.hpp"


class TaskManager {
public:
    RoboTask *current_task = nullptr;
    PriorityQueue<RoboTask> tasks;
    TaskManager();
    void ClearAllTasks();
    void addTask(RoboTask *task, string parameters);
    void run();


};
#endif
