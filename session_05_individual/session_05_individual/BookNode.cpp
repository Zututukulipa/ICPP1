#include "Entities.h"

#include <iostream>

Entities::BookNode::BookNode() {
	next = nullptr;
	data = nullptr;
}

Entities::BookNode::BookNode(Object* initObject) {
	next = nullptr;
	data = initObject;
}

Entities::BookNode::~BookNode()
{
	auto* currentNode = this;
	while (currentNode != nullptr) {
		Entities::BookNode* tmp = currentNode->next;
		delete currentNode;
		currentNode = tmp;
	}
}

Entities::BookNode* Entities::BookNode::newRecord(Object* addedPerson) {
	auto* currentNode = this;
	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}
	auto* newlyCreatedNode = new BookNode(addedPerson);
	currentNode->next = newlyCreatedNode;
	return newlyCreatedNode;
}

Entities::Object* Entities::BookNode::getData() {
	return data;
}

Entities::BookNode* Entities::BookNode::searchRecord(std::string name) {
	auto* currentData = this;
	if (isMatching(currentData->getData, name))
		return currentData;
	while (next != nullptr) {
		if (isMatching(currentData->getData, name))
			return currentData;
		currentData = next;

	}
	return nullptr;
}

Entities::BookNode* Entities::BookNode::searchRecord(int id) {
	auto* currentData = this;
	if (isMatching(currentData->getData, id))
		return currentData;
	while (next != nullptr) {
		if (isMatching(currentData->getData, id))
			return currentData;
		currentData = next;

	}
	return nullptr;
}

bool isMatching(Entities::BookNode* currentData, std::string name) {
	Entities::Person* person = dynamic_cast<Entities::Person*>(currentData->getData());
	return person != nullptr && person->getName = name;
}

bool isMatching(Entities::BookNode* currentData, int id) {
	Entities::Person* person = dynamic_cast<Entities::Person*>(currentData->getData());
	return person != nullptr && person->getId = id;
}

Entities::BookNode* Entities::BookNode::deleteRecord(Entities::BookNode* nodeMarkedForDeletion) {
	auto* currentNode = this;
	while (currentNode != nullptr) {
		Entities::BookNode* tmp = currentNode->next;
		delete currentNode;
		currentNode = tmp;
	}
}