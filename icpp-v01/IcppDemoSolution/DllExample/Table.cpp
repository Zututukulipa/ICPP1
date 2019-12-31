#include "DbApi.h"
#include "TableIterator.h"
#include <iostream>

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
	for (int i = 0; i < rowCount; ++i)
	{
		rows[i] = new Object*[fieldCount];
	}

	return rows;
}

void freeArray(Object*** tmp, int rowCount, int columnCount)
{
	for (int i = 0; i < rowCount; ++i)
	{
		for (int j = 0; j < columnCount; ++j)
		{
			delete tmp[i][j];
		}
	}
	delete[] tmp;
}

Object*** Table::allocateNewArray()
{
	Object*** tmp = new Object **[rowCapacity * 2];
	for (int i = 0; i < rowCapacity * 2; ++i)
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

	rowCapacity *= 2;
	rows = tmp;
}

void Table::insert(Object** row)
{
	bool inCheck = true;
	for (int i = 0; i < fieldCount; ++i)
	{
		if (!row[i]->isType(fields[i]->type))
			inCheck = false;
	}
	if (inCheck) {
		if (rowCapacity < 1)
		{
			initRows();
		}
		if (rowCount == rowCapacity)
		{
			reallocateArray();
		}
		rows[rowCount++] = row;
	}
	else
	{
		std::cout << "Error during insert. Skipping Line" << std::endl;
		delete[] row;
	}
}

void Table::remove(int rowid)
{
	if (rowid <= rowCount && rowid > 0) {
		for (int column = 0; column < fieldCount; ++column)
		{
			auto cell = rows[rowid][column];
			if (cell->isType(FieldType::Integer))
				cell->setInt(0);
			else if (cell->isType(FieldType::Double))
				cell->setDouble(0.0);
			else if (cell->isType(FieldType::String))
				cell->setString("");
		}
	}
	std::cout << "Index out of bounds, skipping operation." << std::endl;
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
	return new TableIterator(rows, rowCount, fieldCount);
}

std::string getFieldWriteString(FieldObject* field)
{
	if (field->type == FieldType::Integer)
	{
		return "int/field/" + field->getName() + ";";
	}
	if (field->type == FieldType::Double)
	{
		return "double/field/" + field->getName() + ";";
	}
	if (field->type == FieldType::String)
	{
		return "string/field/" + field->getName() + ";";
	}
	return "NULL/NULL;";
}

std::string getCellWriteString(Object* object)
{
	if (object != nullptr) {
		if (object->isType(FieldType::Integer))
			return std::to_string(object->getInt()) + "/int;";
		if (object->isType(FieldType::Double))
			return std::to_string(object->getDouble()) + "/double;";
		if (object->isType(FieldType::String))
			return object->getString() + "/string;";
	}
	return "NULL/NULL;";
}

bool isInFile(std::string dbName, std::string tableName)
{
	std::string line;
	std::ifstream myfile(dbName + ".txt");
	bool inFile = false;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (tableName == line)
				return true;
		}
		myfile.close();
	}
	return false;
}

void Table::writeDataToTable()
{
	std::ofstream newFile(getTableName()+".txt");
	std::string field;
	if (newFile.is_open())
	{
		for (int i = 0; i < fieldCount; ++i)
		{
			newFile << getFieldWriteString(fields[i]);
		}
		newFile << std::endl;

		for (int i = 0; i < rowCount; ++i)
		{
			for (int j = 0; j < fieldCount; ++j)
			{
				newFile << getCellWriteString(rows[i][j]);
			}
			newFile << std::endl;
		}
	}
	else
	{
		std::cout << "You're in trouble now Mr!" << std::endl;
	}


	newFile.close();
}

void Table::commit()
{
	if(!isInFile(dbName, getTableName()))
	{
		std::ofstream append(getTableName() + ".txt", std::ios::app);
		if (append.is_open())
		{
			append << std::endl << getTableName();
		}
		append.close();
	}
	
	writeDataToTable();
}
