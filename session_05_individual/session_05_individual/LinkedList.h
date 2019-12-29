#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Person.h"
#include <string>

class LinkedList {
private:
	struct Element;
	Element* head;
public:
	~LinkedList();
	LinkedList();
	void insertElement(Entity::Person person);
	std::string findElement(std::string searchedName) const;
	std::string findElement(int contactId) const;
};
#endif // !LINKED_LIST_H