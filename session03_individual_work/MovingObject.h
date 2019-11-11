#ifndef SESSION03_INDIVIDUAL_WORK_MOVINGOBJECT_H
#define SESSION03_INDIVIDUAL_WORK_MOVINGOBJECT_H


#include "Object.h"

class MovingObject: public Object {
public:
    double getAzimut() const;
	MovingObject();
	MovingObject(double azimut);
	MovingObject(double azimut, int id, int x, int y);
	virtual ~MovingObject();
private:
    double azimut;
};


#endif //SESSION03_INDIVIDUAL_WORK_MOVINGOBJECT_H
