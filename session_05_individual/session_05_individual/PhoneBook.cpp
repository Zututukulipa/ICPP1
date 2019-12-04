#include "Phonebook.h"

void Model::Phonebook::addPerson(Entity::Person addedPerson)
{
	first.insertElement(addedPerson);
}

std::string Model::Phonebook::findPhone(std::string contactName) const
{
	return first.findElement(contactName);
}

std::string Model::Phonebook::findPhone(int contactId) const
{
	return first.findElement(contactId);
}