#include "subsysHeaders/GameObjectHandler.hpp"

GameObjectHandler::GameObjectHandler(){

}

void GameObjectHandler::addObject(std::string identifier, int type, float x, float y) {
    GameObject* obj = query(identifier);
    if (obj == nullptr)
    { /*Object is not in DB*/
        int totalCurrentofType = 0;
        for (auto it = Objects.begin(); it!= Objects.end(); ++it) {
            if (it->type == type)totalCurrentofType+=1;
        }
        if (totalCurrentofType < MaxOfTypes.find(type)->second) 
        {
            Objects.push_back(GameObject(x, y, identifier, type, WidthHeights.find(type)->second.front(), WidthHeights.find(type)->second.back()));

        }
        else 
        {/*We need to update the closest object to it*/
        obj = nullptr;
        float distance = 10000;
        for (auto it = Objects.begin(); it!= Objects.end(); ++it) {
            if (it->type == type) {
                float distBtwObjs = pow(x- *it->x, 2) + pow(y- *it->y, 2);
                if (distBtwObjs < distance) obj = query(it->identifier);
            }
        }
            obj->setX(x);
            obj->setY(y);
        }
    }

    else {
        obj->setX(x);
        obj->setY(y);
    }


    delete obj;
}

void GameObjectHandler::updateObjPos(std::string identifier, int type, float x, float y) {
    GameObject * obj = query(identifier);
    if (obj == nullptr) 
    {
        addObject(identifier, type, x, y);
    }
    else {
        obj->setX(x);
        obj->setY(y);
    }
}

GameObject* GameObjectHandler::query(std::string identifier) { 
    GameObject* obj = nullptr;
    for (auto it = Objects.begin(); it!= Objects.end(); ++it) {
        if(it->checkID(identifier)) {
                auto& val = *it;
                obj = &val;
        }
        return obj;
    }
}
//float x, float y, std::string identifier, int type) {