#include "DbApi.h"

int Object::getInt() const
{
	if(this->isType(FieldType::Integer))
		return ((IntObject*)this)->getInt();
	return 0;
}

double Object::getDouble() const
{
	if (this->isType(FieldType::Double))
		return ((DoubleObject*)this)->getDouble();
	return 0;
}

Object::~Object()
{
}

std::string Object::getString() const
{
	if (this->isType(FieldType::String))
		return ((StringObject*)this)->getString();
	return "";
}

bool Object::isType(FieldType aType) const
{
	return aType == type;
}

void Object::setInt(int aValue)
{
	if (this->isType(FieldType::Integer))
		static_cast<IntObject*>(this)->setInt(aValue);
}

void Object::setDouble(double aValue)
{
	if (this->isType(FieldType::Double))
		static_cast<DoubleObject*>(this)->setDouble(aValue);
}

void Object::setString(std::string aValue)
{
	if (this->isType(FieldType::String))
		static_cast<StringObject*>(this)->setString(aValue);
}






