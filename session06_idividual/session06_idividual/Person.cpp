#include "Person.h"

Person::~Person()
{
}

Person::Person(std::string name, std::string surname, Address houseHold, Date birthDate)
{
	this->_name = name;
	this->_surname = surname;
	this->_houseHold = houseHold;
	this->_birthDate = birthDate;
}

Person::Person()
{
}

std::string Person::getFullName() const
{
	return _name + " " + _surname;
}

Address Person::getHouseHold() const
{
	return _houseHold;
}

Date Person::getBirthDate() const
{
	return _birthDate;
}

void Person::setFullName(std::string firstName, std::string surname)
{
	_name = firstName;
	_surname = surname;
}

void Person::setHouseHold(Address address)
{
	_houseHold = address;
}

void Person::setBirthDate(Date birthDate)
{
	_birthDate = birthDate;
}



std::ostream& operator<<(std::ostream& stream, const Person& person)
{
	std::string name = person.getFullName();
	int size = name.size();
	char siz = (char)size;
	stream.write(&siz, sizeof(siz));
	stream.write(&name[0], size * sizeof(char));
	stream << person.getHouseHold() << person.getBirthDate();
	return stream;
}

std::istream& operator>>(std::istream& stream, Person& person)
{
	std::string name;
	std::string surName;
	Address address;
	Date date;

	char size;
	stream.read(&size, sizeof(char));
	name.resize(size);
	stream.read(&name[0], size);

	stream >> address;
	stream >> date;

	person.setFullName(name, "");
	person.setHouseHold(address);
	person.setBirthDate(date);

	return stream;
}

