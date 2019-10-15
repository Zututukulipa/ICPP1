//
// Created by Zututukulipa on 11/10/2019.
//

#ifndef SESSION03_INDIVIDUAL_WORK_STATICOBJECT_H
#define SESSION03_INDIVIDUAL_WORK_STATICOBJECT_H


#include "Object.h"

enum ObstacleType {
    rock, small_plant, big_plant
};

class StaticObject : Object {
    ObstacleType obstacleType;

    StaticObject(int id, ObstacleType typeOfObstacle);

public:
    ObstacleType getObstacleType() const {
        return obstacleType;
    }

};


#endif //SESSION03_INDIVIDUAL_WORK_STATICOBJECT_H
