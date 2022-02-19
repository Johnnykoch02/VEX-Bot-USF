// #include "./subsysHeaders/TaskManager.hpp"
// //PriorityQueue<RoboTask>::PriorityQueue()'


// TaskManager::TaskManager() {
//     this->tasks = PriorityQueue<RoboTask>();
//     this->current_task = nullptr;
// }

// void TaskManager::addTask(RoboTask *task) {
//     this->tasks.enqueue(task, 0);
// }
// void TaskManager::ClearAllTasks() {
//     this->tasks.deque_all();
//     delete this->current_task; //I think
//     this->current_task = nullptr;
// }

// void TaskManager::run() {
//     if (this->current_task != nullptr)
//     { /* Update and chek our current task*/
//         this->current_task->update();
        
//         if (this->current_task->finishedFlag)
//         { /* Task is complete */
//             delete this->current_task;
//             this->current_task = nullptr;
//         }
//     }
//     else if (tasks.isEmpty() == false)
//     { /* Obtain the next task*/
//         this->current_task = this->tasks.deque();
//     }
//     else
//     {/* Do Nothing?*/
//     // pros::lcd::print(3, "All Tasks Completed.");

//     }
// }
