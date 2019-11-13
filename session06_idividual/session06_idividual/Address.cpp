#include "Address.h"
#include <string>

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
	//stream << address.getStreet() << " " << address.getZip() << " " << address.getCity();
	std::string stringValue = address.getStreet();
	int size = stringValue.size();
	char siz = (char)size;
	stream.write(&siz, sizeof(size));
	stream.write((char*)stringValue.c_str(), size * sizeof(char));


	int zip = address.getZip();
	stream.write((char*)&zip, sizeof(int));

	stringValue = address.getCity();
	size = stringValue.size();
	siz = (char)size;
	stream.write(&siz, sizeof(size));
	stream.write((char*)stringValue.c_str(), size * sizeof(char));
	return stream;
}



std::istream& operator>>(std::istream& stream, Address& address)
{
	std::string city;
	std::string street;

	char size;
	stream.read(&size, sizeof(int));
	street.resize(size);
	stream.read(&street[0], size);


	/*stream.read(&tmp, sizeof(tmp));
	zip = (int)tmp;*/
	int zip;
	stream.read((char*)&zip, sizeof(int));

	stream.read(&size, sizeof(int));
	city.resize(size);
	stream.read(&city[0], size);

	//stream >> street >> city >> zip;
	address.setCity(city);
	address.setStreet(street);
	address.setZip(zip);

	return stream;
}
