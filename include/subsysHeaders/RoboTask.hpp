using namespace std;

#ifndef RoboTask_h
#define RoboTask_h

class TaskManager;

class RoboTask {
public:
    float x, y;
    bool reversed;
    float armFront;
    float armBack;
    float timeDelayAfterFinished;
    int totalOperations;
    bool turnCompleted;

    bool finishedFlag;


    RoboTask(RoboTask *task);
    ~RoboTask();
    /* X: X Coordinate, Y: Y coordinate, Reversed: Reverses approach orientation, 
    Lift: desired lift state, intake: desired intake state, arm: desired arm position, 
    timeDelay: time to be delayed after task completion. */
    RoboTask(float x, float y, bool reversed, float armFront, float armBack, float timeDelayAfterFinished);
    void update();

};

#endif
