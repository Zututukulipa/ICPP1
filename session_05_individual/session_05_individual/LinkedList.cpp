#include<stdexcept>
#include "LinkedList.h"

class LinkedList::Element {
public:
	Entity::Person data;
	Element* next;
};

LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::~LinkedList()
{
	Element* current = head;
	while (current->next != nullptr)
	{
		delete current;
		current = current->next;
	}
}
void LinkedList::insertElement(Entity::Person addedPerson)
{
	if (addedPerson.getId() < 0 || addedPerson.getName().empty())
	{
		throw std::invalid_argument("Invalid argument");
	}
	Element* newElement = new LinkedList::Element();
	newElement->data = addedPerson;
	if (head == nullptr)
	{
		head = newElement;
		head->next = nullptr;
	}

	Element* current = nullptr;
	current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = newElement;
	current->next->data = addedPerson;
	current = current->next;
	current->next = nullptr;

}

std::string LinkedList::findElement(std::string searchedName) const
{
	Element* current = nullptr;
	current = head;
	if (head == nullptr)
	{
		throw std::exception("List is not initialized");
	}

	current = head;
	while (current != nullptr)
	{
		if (current->data.getName() == searchedName)
		{
			return current->data.getTelephone();

		}
		current = current->next;
	}
	throw std::exception("Contact not found");

}

std::string LinkedList::findElement(int contactId) const
{
	Element* current = nullptr;
	current = head;
	if (head == nullptr)
	{
		throw std::exception("List is not initialized");
	}
	current = head;
	while (current != nullptr)
	{
		if (current->data.getId() == contactId)
		{
			return current->data.getTelephone();

		}
		else {
			current = current->next;
		}
	}
	throw std::exception("No contact found");

}