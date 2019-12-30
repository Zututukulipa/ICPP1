#include <democlass.h>
#include <DbApi.h>
#include "TableIterator.h"
#include <iostream>

int main() {
	Db *dat = Db::open("data.txt");
	auto tab = dat->openOrCreateTable("TEST_TABLE", 0,nullptr);
	TableIterator *iterator = (TableIterator*)tab->select();
	while(iterator->moveNext())
	{
		auto *row = iterator->getRow();
		if((FieldObject*)row[0]->isType(FieldType::Integer))
			std::cout << "___" << std::endl;
		row = nullptr;
	}
	dat->close();
	DemoClass dc{};
	dc.HelloWorld();

	return 0;
}
