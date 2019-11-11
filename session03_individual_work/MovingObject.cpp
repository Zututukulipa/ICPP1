#include "MovingObject.h"

double MovingObject::getAzimut() const {
    return azimut;
}

MovingObject::MovingObject()
{
	azimut = 90;
}

MovingObject::MovingObject(double azimut)
{
	this->azimut = azimut;
}

MovingObject::MovingObject(double azimut, int id, int x, int y):Object(id, x, y)
{
	this->azimut = azimut;
}

MovingObject::~MovingObject()
{
}
