using namespace std;

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// #include <string.h>

class GameObject {
    private:
    public:
    char identifier[5];
    float *x;
    float width;
    float height;
    float * y;
    int type;
    
    GameObject(float x, float y, char identifier[5], int type) {
        this->x[0] = x;
        this->y[0] = y;
        for (int i = 0; i < (sizeof identifier / sizeof identifier[0]); i++) {
            this->identifier[i] = identifier[i];
        }
    }

    void setX(float x) {    
        this->x[0] = x;
    }
    void setY(float y) {
        this->y[0] = y;
    }

    bool checkID(char identifier[5]) { 
    
         for (int i = 0; i < (sizeof identifier / sizeof identifier[0]); i++) {
            if (this->identifier[i] == identifier[i]) continue;
            else return false;
        }

        return true;
    }

};

#endif