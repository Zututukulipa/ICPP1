#include "Address.h"

Address::Address(std::string street, std::string city, int zip)
{
	this->_street = street;
	this->_city = city;
	this->_zip = zip;
}

Address::Address()
{
	_zip = 0;
	_street = "";
	_city = "";
}

std::string Address::getCity() const
{
	return _city;
}

std::string Address::getStreet() const
{
	return _street;
}

int Address::getZip() const
{
	return _zip;
}

void Address::setCity(std::string newCity)
{
	this->_city = newCity;
}

void Address::setStreet(std::string newStreet)
{
	this->_street = newStreet;
}

void Address::setZip(int newZip)
{
	this->_zip = newZip;
}

std::ostream& operator<<(std::ostream& stream, const Address& address)
{
	stream << address.getStreet() << " " << address.getZip() << " " << address.getCity();
	return stream;

}

std::istream& operator>>(std::istream& stream, Address& address)
{
	std::string city;
	std::string street;
	int zip;

	stream >> street >> city >> zip;

	address.setCity(city);
	address.setStreet(street);
	address.setZip(zip);

	return stream;
}
