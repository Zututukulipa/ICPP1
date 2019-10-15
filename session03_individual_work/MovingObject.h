//
// Created by Zututukulipa on 11/10/2019.
//

#ifndef SESSION03_INDIVIDUAL_WORK_MOVINGOBJECT_H
#define SESSION03_INDIVIDUAL_WORK_MOVINGOBJECT_H


#include "Object.h"

class MovingObject: public Object {
public:
    double getAzimut() const;

private:
    double azimut;


};


#endif //SESSION03_INDIVIDUAL_WORK_MOVINGOBJECT_H
