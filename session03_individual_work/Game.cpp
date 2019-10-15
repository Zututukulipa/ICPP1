//
// Created by Zututukulipa on 11/10/2019.
//

#include <cmath>
#include "Game.h"
#include "StaticObject.h"


void Game::addObject(Object *o) {
    objects[amountOfObjects++] = o;
}

int *Game::findIdOfStaticObjects(double xMin, double xMax, double yMin, double yMax) {
    int* counter = nullptr;
    for (int i = 0; i < amountOfObjects; ++i) {
        StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
        double currentX = objects[i]->getX();
        double currentY = objects[i]->getY();
        if (so != nullptr && currentX > xMin && currentY > yMin && currentX < xMax && currentY < yMax)
            counter++;
    }
    return counter;
}

MovingObject **Game::findMovingObjectsInArea(double center_x, double center_y, double radius) {
    MovingObject** pMovingObjects = new MovingObject*[3];
    int counter = 0;
    for (int i = 0; i < amountOfObjects; ++i) {
        MovingObject* mo = dynamic_cast<MovingObject*>(objects[i]);
        if(mo != nullptr) {
            MovingObject *selectedObject = dynamic_cast<MovingObject *>(objects[i]);
            double currentX = selectedObject->getX();
            double currentY = selectedObject->getY();
            if ((pow(currentX - center_x,2) + pow(currentY - center_y,2)) < pow(radius,2))
                pMovingObjects[counter++] = selectedObject;
        }
    }
    return pMovingObjects;
}

MovingObject **Game::findMovingObjectsInArea(double center_x, double center_y, double radius, double azimutMin, double azimutMax) {
    MovingObject** pMovingObjects = new MovingObject*[3];
    int counter = 0;
    for (int i = 0; i < amountOfObjects; ++i) {
        MovingObject* mo = dynamic_cast<MovingObject*>(objects[i]);
        if(mo != nullptr) {
            MovingObject *selectedObject = dynamic_cast<MovingObject *>(objects[i]);
            double currentX = selectedObject->getX();
            double currentY = selectedObject->getY();
            double currentAzimut = selectedObject->getAzimut();
            if ((pow(currentX - center_x,2) + pow(currentY - center_y,2)) < pow(radius,2) && currentAzimut >= azimutMin && currentAzimut <= azimutMax)
                pMovingObjects[counter++] = selectedObject;
        }
    }
    return pMovingObjects;
}
