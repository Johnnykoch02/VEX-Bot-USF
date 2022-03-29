using namespace std;

#ifndef GAMEOBJECTHANDLER_H
#define GAMEOBJECTHANDLER_H

#include "subsysHeaders/GameObject.hpp"

class GameObjectHandler { 
    public:
      std::list<GameObject> Objects;
      const std::Map<int, int> MaxOfTypes = {
        {2, 2}, //REDGOAL
        {6, 2}, //BLUEGOAL
        {3, 3} //NEUTRALGOAL
        {8, 1}, //REDPLATFORM
        {9, 1}, //BLUEPLATFORM
    };






};


#endif