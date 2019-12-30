#include "DbApi.h"

StringObject::StringObject(std::string v)
{
	value = v;
}

std::string StringObject::getString() const
{
	return value;
}

void StringObject::setString(std::string aValue)
{
	value = aValue;
}

