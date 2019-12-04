#include "Person.h"

void Entity::Person::setId(int newId) {
	id = newId;
}
void Entity::Person::setName(std::string newName) {
	name = newName;
}
void Entity::Person::setTelephone(std::string newTelephone)
{
	telephone = newTelephone;
}

int Entity::Person::getId() const {
	return id;
}

std::basic_string<char> Entity::Person::getName() const
{
	return name;
}std::string Entity::Person::getTelephone() const {
	return telephone;
}


