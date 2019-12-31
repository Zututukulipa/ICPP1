#include "DbApi.h"

IntObject::IntObject()
{
	value = 0;
	type = FieldType::Integer;
}

IntObject::IntObject(int v)
{
	value = v;
	type = FieldType::Integer;
}

int IntObject::getInt()const
{
	return value;
}

void IntObject::setInt(int aValue)
{
	value = aValue;
}
