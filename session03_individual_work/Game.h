//
// Created by Zututukulipa on 11/10/2019.
//

#ifndef SESSION03_INDIVIDUAL_WORK_GAME_H
#define SESSION03_INDIVIDUAL_WORK_GAME_H


#include "Object.h"
#include "MovingObject.h"

class Game {
    Object **objects;
public:
    static int amountOfObjects;
    void addObject(Object *o);

    int* findIdOfStaticObjects(double xMin, double xMax, double yMin, double yMax);

    MovingObject** findMovingObjectsInArea(double x, double y, double r);

    MovingObject** findMovingObjectsInArea(double x, double y, double r, double azimutMin, double azimutMax);
};
    int amountOfObjects = 0;

#endif //SESSION03_INDIVIDUAL_WORK_GAME_H
