#pragma once
#include <iostream>
class Address
{
private:
	std::string _street, _city;
	int _zip;
public:
	Address(std::string street, std::string city, int zip);
	Address();
	std::string getCity() const;
	std::string getStreet() const;
	int getZip() const;

	void setCity(std::string newCity);
	void setStreet(std::string newStreet);
	void setZip(int newZip);
};

std::ostream& operator<<(std::ostream&, const Address&);
std::istream& operator>>(std::istream&, Address&);

