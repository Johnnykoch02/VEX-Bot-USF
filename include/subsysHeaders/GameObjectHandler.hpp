using namespace std;

#ifndef GAMEOBJECTHANDLER_H
#define GAMEOBJECTHANDLER_H

#include "subsysHeaders/GameObject.hpp"
#include <list>
#include <map>
#include <vector>
#include <string>
#include <math.h>
class GameObjectHandler { 
    public:
      std::list<GameObject> Objects;
      const std::map<int, int> MaxOfTypes = {
        {2, 2}, //REDGOAL
        {6, 2}, //BLUEGOAL
        {3, 3}, //NEUTRALGOAL
        {8, 1}, //REDPLATFORM
        {9, 1} //BLUEPLATFORM
    };
    const std::map<int, std::vector<float>> WidthHeights = {
        {2, {13.5,13.5}}, //REDGOAL
        {6, {13.5,13.5}}, //BLUEGOAL
        {3, {13.5,13.5}},//NEUTRALGOAL
        {8, {20,53}}, //REDPLATFORM
        {9, {20,53}}, //BLUEPLATFORM
    };

    GameObjectHandler();
    GameObject* query(std::string identifier);
    GameObject* getClosestObj(int type, float x, float y);
    void updateObjPos(std::string identifier,int type, float x, float y);

    void addObject(std::string identifier, int type, float x, float y);




};


#endif