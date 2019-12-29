#include <db.h>
#include <iostream>

using namespace std;

int main() {
	// Vytvoření db
	Db* db = Db::open("testdb");

	// Vytvoření tabulky
	auto idField = Db::Field("id", FieldType::Integer);
	auto nameField = Db::Field("name", FieldType::String);
	auto userFields = combineToDefinition(idField, nameField);
	Table* users = db->openOrCreateTable("users", 2, userFields);

	// Vložení řádku do tabulky	
	auto id = Db::Int(15);
	auto name = Db::String("Josef");
	auto row = combineToRow(id, name);
	users->insert(row);

	// Select
	auto it = users->select();
	while (it->moveNext()) 
	{
		auto row = it->getRow();

		cout << row[0]->getInt() << ": " << row[1]->getString() << endl;
	}
	it->close();

	// Uložení tabulky na disk
	users->commit();

	// Uzavření tabulky
	users->close();

	// Uzavření db
	db->close();

	cin.get();
	return 0;
}