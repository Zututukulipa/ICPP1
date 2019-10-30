#pragma once

#include <iostream>
namespace Entities {


	class Object {
	public:
		virtual ~Object() = 0;
		Object();
	};

	class Person: public Object
	{
	private:
		std::string name;
		std::string telephone;
		int id;
	public:
		std::string getName();
		std::string getTelephone();
		int getId();

		void setName(std::string newName);
		void setTelephone(std::string newTelephone);
		void setId(int newId);

		Person(std::string name, std::string telephone, int id);
	};


	class BookNode {
	private:
		BookNode* next;
		Object* data;
	public:
		BookNode();
		~BookNode();
		BookNode(Object* initObject);
		BookNode* newRecord(Object* data);
		BookNode* searchRecord(std::string name);
		BookNode* searchRecord(int id);
		BookNode* deleteRecord(BookNode* nodeMarkedForDeletion);
		Object* getData();

	};
}
namespace Model {
	class PhoneBook
	{
	private:
		Entities::BookNode* first;
	public:
		void addRecord(Entities::Person* addedPerson);
		std::string findContact(std::string contactName) const;
		std::string findContact(int contactId) const;

	};

}