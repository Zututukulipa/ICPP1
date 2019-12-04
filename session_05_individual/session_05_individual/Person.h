#ifndef PERSON_H
#define PERSON_H

#include<string>
namespace Entity {
	class Person
	{
	private:
		std::string name;
		int id;
		std::string telephone;
	public:
		void setName(std::string name);
		void setId(int id);
		void setTelephone(std::string phone);
		std::string getName() const;
		int getId() const;
		std::string getTelephone() const;

	};
}
#endif // !PERSON_H
