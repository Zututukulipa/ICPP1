#include "DbApi.h"

FieldObject::FieldObject()
{
	type = FieldType::Integer;
}

FieldObject::FieldObject(std::string name, FieldType type)
{
	this->name = name;
	this->type = type;
}

bool FieldObject::isType(FieldType compType) const
{
	return type == compType;
}

