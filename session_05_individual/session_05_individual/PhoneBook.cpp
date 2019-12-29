#include "Phonebook.h"

void Model::PhoneBook::addPerson(Entity::Person addedPerson)
{
	first.insertElement(addedPerson);
}

std::string Model::PhoneBook::findPhone(std::string contactName) const
{
	return first.findElement(contactName);
}

std::string Model::PhoneBook::findPhone(int contactId) const
{
	return first.findElement(contactId);
}