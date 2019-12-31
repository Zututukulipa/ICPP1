#include <democlass.h>
#include <DbApi.h>
#include "TableIterator.h"
#include <iostream>

void write_out_row(Table* tab, Object** row)
{
	for (int i = 0; i < tab->getFieldCount(); ++i)
	{
		if (row[i] != nullptr) {
			if ((FieldObject*)row[i]->isType(FieldType::Integer)) {
				std::cout << "-----------" << std::endl;
				std::cout << "|_INTEGER_|" << std::endl;
				std::cout << "|_" << static_cast<IntObject*>(row[i])->value << "__|" << std::endl;
				std::cout << "-----------" << std::endl;
			}
			else if ((FieldObject*)row[i]->isType(FieldType::Double)) {
				std::cout << "-----------" << std::endl;
				std::cout << "|_DOUBLE__|" << std::endl;
				std::cout << "|_" << static_cast<DoubleObject*>(row[i])->value << "__|" << std::endl;
				std::cout << "-----------" << std::endl;
			}
			else if ((FieldObject*)row[i]->isType(FieldType::String)) {
				std::cout << "-----------" << std::endl;
				std::cout << "|_STRING__|" << std::endl;
				std::cout << "|_" << static_cast<StringObject*>(row[i])->value << "__|" << std::endl;
				std::cout << "-----------" << std::endl;
			}
		}else
		{
			std::cout << "-----------" << std::endl;
			std::cout << "|___NULL__|" << std::endl;
			std::cout << "-----------" << std::endl;
		}
		
	}
}

int main() {
	Db *dat = Db::open("db_test");
	auto tab = dat->openOrCreateTable("TEST_TABLE", 0,nullptr);
	auto fc = tab->getFieldCount();
	auto rc = tab->getRowCount();
	auto f = tab->getFields();
	auto tn = tab->getTableName();
	auto dn = tab->getDatabaseName();
	TableIterator *iterator = static_cast<TableIterator*>(tab->select());
	while(iterator->moveNext())
	{
		auto row = iterator->getRow();
		write_out_row(tab, row);
		std::cout << std::endl;
	}
	tab->insert(new Object * [5]{ Db::Int(333), Db::Int(321), Db::Double(20.0100002), Db::String("Added String Via Database YEEEEY") });
	auto row = iterator->getRow();
	auto rnum = iterator->getRowId();
	tab->remove(rnum - 2);
	write_out_row(tab, row);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "||||||||||||||||||||||||||||" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	iterator = static_cast<TableIterator*>(tab->select());
	while (iterator->moveNext())
	{
		auto row = iterator->getRow();
		write_out_row(tab, row);
		std::cout << std::endl;
	}
	tab->commit();
	dat->close();
	DemoClass dc{};
	dc.HelloWorld();

	return 0;
}
