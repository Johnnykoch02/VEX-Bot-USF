using namespace std;

#ifndef GAMEOBJECTHANDLER_H
#define GAMEOBJECTHANDLER_H

#include "subsysHeaders/GameObject.hpp"
#include <list>
#include <map>
#include <vector>
#include <string>

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
        {2, {20,20}}, //REDGOAL
        {6, {20,20}}, //BLUEGOAL
        {3, {20,20}},//NEUTRALGOAL
        {8, {80,40}}, //REDPLATFORM
        {9, {80,40}}, //BLUEPLATFORM
    };

    GameObjectHandler();
    GameObject* query(std::string identifier);

    void updateObjPos(std::string identifier,int type, float x, float y);

    void addObject(std::string identifier, int type, float x, float y);




};


#endif