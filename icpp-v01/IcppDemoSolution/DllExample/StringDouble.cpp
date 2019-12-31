#include "DbApi.h"

StringObject::StringObject()
{
	value = "";
	type = FieldType::String;
}

StringObject::StringObject(std::string v)
{
	value = v;
	type = FieldType::String;
}

std::string StringObject::getString() const
{
	return value;
}

void StringObject::setString(std::string aValue)
{
	value = aValue;
}

