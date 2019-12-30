#include "DbApi.h"

DoubleObject::DoubleObject(double v)
{
	value = v;
}

double DoubleObject::getDouble() const
{
	return value;
}


void DoubleObject::setDouble(double aValue)
{
	value = aValue;
}
