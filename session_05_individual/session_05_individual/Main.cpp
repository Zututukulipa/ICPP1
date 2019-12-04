#include <iostream>
#include "Phonebook.h"
#include "Person.h"

int main() {
	auto* contacts = new Model::Phonebook;

	for (size_t i = 0; i < 150; i++)
	{
		Entity::Person mockup = Entity::Person();
		mockup.setId(i);
		mockup.setName("TESTER"+std::to_string(i));
		mockup.setTelephone("7298317");
		contacts->addPerson(mockup);

	}
	
	auto found = contacts->findPhone(6);
	std::cout << found << std::endl;
	delete contacts;
	return 0;
}