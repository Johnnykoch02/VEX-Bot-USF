using namespace std;

#ifndef RoboTask_h
#define RoboTask_h

class TaskManager;

class RoboTask {
public:
    float x, y;
    bool lift;
    bool intake;
    float arm;
    int totalOperations;

    bool finishedFlag;


    RoboTask(RoboTask *task);
    ~RoboTask();
    RoboTask(float x, float y, bool lift, bool intake, float arm);
    void update();

};

#endif
