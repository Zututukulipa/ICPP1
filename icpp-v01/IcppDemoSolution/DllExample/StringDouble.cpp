#include "DbApi.h"

std::string StringObject::getString() const
{
	return value;
}

void StringObject::setString(std::string aValue)
{
	value = aValue;
}

