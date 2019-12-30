#include "DbApi.h"
#include "TableIterator.h"

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

Object*** Table::initRows()
{
	rowCapacity = 5;

	rows = new Object **[rowCapacity];
	for (int i = 0; i < rowCount; ++i) {
		rows[i] = new Object*[fieldCount];
	}

	// Null out the pointers contained in the array:
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < fieldCount; ++j) {
			rows[i][j] = NULL;
		}
	}
	return rows;
}

void freeArray(Object*** tmp, int rowCount, int columnCount)
{
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < columnCount; ++j)
		{
			delete tmp[i][j];
		}
	}
	delete[] tmp;
}

Object*** Table::allocateNewArray()
{
	Object*** tmp = new Object **[rowCapacity*2];
	for (int i = 0; i < rowCapacity*2; ++i)
		tmp[i] = new Object * [fieldCount];
	return tmp;
}

void Table::copyToNewArray(Object*** tmp)
{
	for (int i = 0; i < rowCapacity; ++i)
	{
		for (int j = 0; j < fieldCount; ++j)
		{
			tmp[i][j] = rows[i][j];
		}
	}
}

void Table::reallocateArray()
{
	Object*** tmp = allocateNewArray();

	copyToNewArray(tmp);

	freeArray(rows, rowCount, fieldCount);
	rowCapacity *= 2;
	rows = tmp;
}

void Table::insert(Object** row)
{
	if(rowCapacity < 1)
	{
		initRows();
	}
	if(rowCount == rowCapacity)
	{
		reallocateArray();
	}
	
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
	return new TableIterator(rows, rowCount, fieldCount);
}

void Table::commit()
{
	//TODO Implement saving into file.
}













