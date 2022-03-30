using namespace std;

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

class GameObject {
    private:
    public:
    std::string identifier;
    float *x;
    float width;
    float height;
    float * y;
    int type;
    
    GameObject(float x, float y, std::string identifier, int type, float width, float height) {
        this->x[0] = x;
        this->y[0] = y;
        this->identifier = identifier;
    }

    void setX(float x) {    
        this->x[0] = x;
    }
    
    void setY(float y) {
        this->y[0] = y;
    }

    bool checkID(std::string identifier) { 
         for (int i = 0; i < identifier.length(); i++) {
            if (i < this->identifier.length())
             if (this->identifier[i] == identifier[i]) continue;
            else return false;
        }

        return true;
    }

};

#endif