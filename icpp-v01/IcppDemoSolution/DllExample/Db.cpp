#include "DbApi.h"
#include <iostream>

Db* Db::open(const std::string databasePath)
{
	std::string line;
	std::ifstream myfile;
	myfile.open(databasePath, std::ios::in);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::cout << line << std::endl;
		}
		myfile.close();
	}else 
		std::cout << "Unable to open file";


	return nullptr;
}

void Db::close()
{
	for (unsigned int i = 0; i < this->tables.size(); ++i)
	{
		delete tables[i];
	}
	delete[] selectedTable;
	std::cout << "Table Closed." << std::endl;
}

Table* Db::createTable(std::string tableName, int fieldAmount, FieldObject** tableFields)
{
	Table* table = new Table();
	table->setDatabaseName(this->getDatabaseName());
	table->setFields(tableFields);
	table->setFieldCount(fieldAmount);
	table->setTableName(tableName);
	return table;
}

Table* Db::get_value(std::string name)
{
	for (unsigned int i = 0; i < this->tables.size(); ++i)
	{
		if (tables[i]->getDatabaseName() == name)
			return tables[i];
	}
	return nullptr;
}

Table* Db::openTable(std::string name)
{
	return get_value(name);
}

Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	Table* table = get_value(name);
	if (table == nullptr)
	{
		table = new Table();
		table->setDatabaseName(this->getDatabaseName());
		table->setTableName(name);
		table->setFieldCount(fieldsCount);
		table->setFields(fields);
		return table;
	}
	return table;

}

void Db::setDatabaseName(std::string aDatabaseName)
{
	this->databaseName = aDatabaseName;
}

std::string Db::getDatabaseName() const
{
	return this->databaseName;
}