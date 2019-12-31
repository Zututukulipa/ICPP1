#include "DbApi.h"

DoubleObject::DoubleObject()
{
	value = 0.0;
	type = FieldType::Double;
}

DoubleObject::DoubleObject(double v)
{
	value = v;
	type = FieldType::Double;
}

double DoubleObject::getDouble() const
{
	return value;
}


void DoubleObject::setDouble(double aValue)
{
	value = aValue;
}
