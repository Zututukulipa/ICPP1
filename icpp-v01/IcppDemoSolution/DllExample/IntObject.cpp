#include "DbApi.h"

IntObject::IntObject(int v)
{
	value = v;
}

int IntObject::getInt()const
{
	return value;
}

void IntObject::setInt(int aValue)
{
	value = aValue;
}
