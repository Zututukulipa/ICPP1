#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Person.h"
#include "LinkedList.h"

namespace Model
{
	class Phonebook
	{
	private:
		LinkedList first;
	public:
		void addPerson(Entity::Person p1);
		std::string findPhone(std::string name) const;
		std::string findPhone(int id) const;
	};
}

#endif // !PHONEBOOK_H