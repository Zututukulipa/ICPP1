#include "Person.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

bool is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void uloz() {
	Person* personArray = new Person[100];
	Date* date = new Date(20, 3, 1999);
	std::ofstream stream("output.dat", std::ofstream::binary);
	Address* address = new Address("street", "city", 12345);
	for (size_t i = 0; i < 100; i++)
	{
		personArray[i].setFullName("Jmeno", "Prijmeni");
		personArray[i].setBirthDate(*date);
		personArray[i].setHouseHold(*address);
		stream << personArray[i];
	}
	stream.close();
	delete[] personArray;
}
void nacti() {
	int recordCount = 0;
	std::ifstream stream("output.dat");
	std::string s;
	std::string name;
	std::string surname;
	std::string street;
	std::string city;
	int zip;
	int year;
	int month;
	int day;
	if (!is_empty(stream)) {
		/*	while (std::getline(stream, s, ' '))
			{
				++recordCount;
			}
			recordCount = recordCount/8;

			stream.clear();
			stream.seekg(0, std::ios_base::beg);*/

		Person* personArray = new Person[10];
		int tmp = 0;
		recordCount = 0;

		int t = 0;
		for (size_t i = 0; i < 10; i++)
		{
			stream >> personArray[i];
			std::cout << personArray[i].getFullName() << "\n" << personArray[i].getBirthDate().getYear() << std::endl;
		}







		delete[] personArray;
	}
}

int main() {
	uloz();
	nacti();

	return 0;
}


