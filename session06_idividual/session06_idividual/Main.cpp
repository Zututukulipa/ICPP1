#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

void uloz() {
	Person* personArray = new Person[3];
	Date* date = new Date(20, 3, 1999);
	std::ofstream stream("output.txt");
	Address* address = new Address("street", "city", 12345);
	for (size_t i = 0; i < 3; i++)
	{
		personArray[i].setFullName("Jmeno", "Prijmeni");
		personArray[i].setBirthDate(*date);
		personArray[i].setHouseHold(*address);
		stream << personArray[i];
	}
	stream.close();
}
void nacti() {
	int recordCount = 0;
	std::ifstream stream("output.txt");
	std::string s;
	std::string name;
	std::string surname;
	std::string street;
	std::string city;
	int zip;
	int year;
	int month;
	int day;

	while (std::getline(stream, s))
	{
		++recordCount;
	}

	stream.seekg(0, std::ios_base::beg);

	Person* personArray = new Person[recordCount];

	// :(
	for (int i = 0; i < recordCount; i++) {

		stream >> personArray[i];

		std::cout << personArray[i];

	}

	delete[] personArray;
}

int main() {
	nacti();

	return 0;
}


