#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "./subsysHeaders/RoboTask.hpp"
#include "./subsysHeaders/PriorityQueue.hpp"


class TaskManager {
public:
    RoboTask *current_task;
    PriorityQueue<RoboTask> tasks;
    TaskManager();
    void ClearAllTasks();
    void addTask(RoboTask *task, string parameters);
    void run();


};
#endif
