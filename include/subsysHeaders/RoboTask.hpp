using namespace std;

#ifndef RoboTask_h
#define RoboTask_h

#include <tuple>
#include <string>

class TaskManager;

class RoboTask {
public:
    float *x;
    float *y;
    bool reversed;
    float armFront;
    float timeDelayAfterFinished;
    int totalOperations;
    bool turnCompleted;
    std::tuple<std::string, int> var_changes;

    bool finishedFlag;


    RoboTask(RoboTask *task);
    ~RoboTask();
    /* X: X Coordinate, Y: Y coordinate, Reversed: Reverses approach orientation, 
    Lift: desired lift state, intake: desired intake state, arm: desired arm position, 
    timeDelay: time to be delayed after task completion. */
    RoboTask(float *x, float* y, bool reversed, float armFront, float timeDelayAfterFinished);
    RoboTask(float *x, float* y, bool reversed, float armFront, float timeDelayAfterFinished, std::tuple<std::string, int> var_changes);
    void init();
    void update();

};

#endif
