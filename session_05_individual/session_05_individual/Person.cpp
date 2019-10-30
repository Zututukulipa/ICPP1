#include "Entities.h"

void Entities::Person::setId(int newId) {
	id = newId;
}
Entities::Person::Person(std::string name, std::string telephone, int id) {
	this->name = name;
	this->telephone = telephone;
	this->id = id;
}
void Entities::Person::setName(std::string newName) {
	name = newName;
}void Entities::Person::setTelephone(std::string newTelephone) {
	telephone = newTelephone;
}
int Entities::Person::getId() {
	return id;
}std::string Entities::Person::getName() {
	return name;
}std::string Entities::Person::getTelephone() {
	return telephone;
}
