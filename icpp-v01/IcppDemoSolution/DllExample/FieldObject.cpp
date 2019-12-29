#include "DbApi.h"

FieldObject::FieldObject()
{
	type = FieldType::Integer;
}

bool FieldObject::isType(FieldType compType) const
{
	return type == compType;
}

