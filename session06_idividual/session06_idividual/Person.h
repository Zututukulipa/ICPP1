#pragma once
#include "Address.h"
#include "Date.h"
class Person
{
private:
	std::string _name, _surname;
	Address _houseHold;
	Date _birthDate;
public:
	~Person();
	Person(std::string name, std::string surname, Address houseHold, Date birthDate);
	Person();
	std::string getFullName() const;
	Address getHouseHold() const;
	Date getBirthDate() const;
	
	void setFullName(std::string firstName, std::string surname);
	void setHouseHold(Address address);
	void setBirthDate(Date birthDate);
};


std::ostream& operator<<(std::ostream&, const Person&);
std::istream& operator>>(std::istream&, Person&);



