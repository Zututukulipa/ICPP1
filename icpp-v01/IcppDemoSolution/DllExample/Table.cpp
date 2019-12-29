#include "DbApi.h"

int Table::getRowCount() const
{
	return rowCount;
}

int Table::getFieldCount() const
{
	return fieldCount;
}

FieldObject** Table::getFields() const
{
	return fields;
}

std::string Table::getTableName() const
{
	return name;
}

std::string Table::getDatabaseName() const
{
	return dbName;
}

void Table::setDatabaseName(std::string aDatabaseName)
{
	dbName = aDatabaseName;
}

void Table::setFieldCount(int aFieldCount)
{
	fieldCount = aFieldCount;
}

void Table::setFields(FieldObject** aFields)
{
	fields = aFields;
}

void Table::setTableName(std::string aTableName)
{
	name = aTableName;
}

void Table::insert(Object** row)
{
	rows[rowCount++] = row;
}

void Table::remove(int rowid)
{
	for (int column = 0; column < fieldCount; ++column)
		delete rows[rowid][column];
}

void Table::close()
{
	for (int rowId = 0; rowId < rowCount; ++rowId)
		for (int column = 0; column < fieldCount; ++column)
			delete rows[rowId][column];
	delete[] rows;
	delete[] fields;
}

Iterator* Table::select()
{
	//TODO Implement Iterator first.
	return nullptr;
}

void Table::commit()
{
	//TODO Implement saving into file.
}













