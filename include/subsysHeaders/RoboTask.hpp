using namespace std;

#ifndef RoboTask_h
#define RoboTask_h

class TaskManager;

class RoboTask {
public:
    float x, y;
    bool lift;
    bool intake;

    bool finishedFlag = false;


    RoboTask(RoboTask *task);
    RoboTask(float x, float y, bool lift, bool intake);
    void init();
    void update();

};

#endif
