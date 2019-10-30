#include "Entities.h"
#include <iostream>

void Model::PhoneBook::addRecord(Entities::Person* addedPerson)
{
	first->newRecord(addedPerson);
}

 std::string Model::PhoneBook::findContact(std::string contactName) const
{
	auto* searchedNode = first->searchRecord(contactName);
	Entities::Person* foundPerson = dynamic_cast<Entities::Person*>(searchedNode->getData);
	if (foundPerson != nullptr)
		return foundPerson->getTelephone();
	
	throw(-123);
}

 inline std::string Model::PhoneBook::findContact(int contactId) const
 {
	 auto* searchedNode = first->searchRecord(contactId);
	 Entities::Person* foundPerson = dynamic_cast<Entities::Person*>(searchedNode->getData);
	 if (foundPerson != nullptr)
		 return foundPerson->getTelephone();

	 throw(-123);
 }

