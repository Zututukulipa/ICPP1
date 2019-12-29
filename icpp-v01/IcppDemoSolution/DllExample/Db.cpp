#include "DbApi.h"
#include <iostream>
#include <sstream>

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
	std::vector<std::string> tokens;
	unsigned int prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	}
	while (pos < str.length() && prev < str.length());
	return tokens;
}

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
{
	std::vector<std::string> result;
	std::string line;
	std::getline(str, line);

	std::stringstream lineStream(line);
	std::string cell;

	while (std::getline(lineStream, cell, ';'))
	{
		result.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return result;
}

void parseLine(const std::vector<std::basic_string<char>>& source)
{


}

Db* Db::open(const std::string databasePath)
{
	Db *dat = new Db();
	dat->focusedFile = databasePath;
	dat->setDatabaseName(databasePath);
	return dat;
}

void Db::close()
{
	for (unsigned int i = 0; i < this->tables.size(); ++i)
	{
		delete tables[i];
	}
	std::cout << "Table Closed." << std::endl;
}

Table* Db::createTable(std::string tableName, int fieldAmount, FieldObject** tableFields)
{
	Table* table = new Table();
	table->setDatabaseName(this->getDatabaseName());
	table->setFields(tableFields);
	table->setFieldCount(fieldAmount);
	table->setTableName(tableName);
	tables.push_back(table);
	return table;
}


Table* Db::openTable(std::string name)
{
	for (unsigned int i = 0; i < this->tables.size(); ++i)
	{
		if (tables[i]->getDatabaseName() == name)
			return tables[i];
	}
	std::ifstream myfile;
	Table* table = nullptr;
	std::string tableName;
	std::vector<FieldObject*> fieldTypes;
	unsigned int currentField = 0;
	std::vector<Object*> row;
	std::string cellType;
	std::string cellContent;
	bool setup = true;

	myfile.open(focusedFile, std::ios::in);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			auto result = getNextLineAndSplitIntoTokens(myfile);

			for (unsigned int i = 0; i < result.size() - 1; ++i)
			{
				auto splitField = split(result[i], "/");
				cellContent = splitField[0];
				cellType = splitField[1];
				if (cellType == "table" && cellContent == name)
				{
					table = new Table();
					tableName = cellContent;
					break;
				}if (!tableName.empty()) {
					if (cellType == "field")
					{
						if (cellContent == "int")
							fieldTypes.push_back(new FieldObject(splitField[2], FieldType::Integer));
						else if (cellContent == "double")
							fieldTypes.push_back(new FieldObject(splitField[2], FieldType::Double));
						else if (cellContent == "string")
							fieldTypes.push_back(new FieldObject(splitField[2], FieldType::String));
						++currentField;
					}
					else if (cellType == "int" && i < currentField)
					{
						row.push_back(new IntObject(std::stoi(cellContent)));
					}
					else if (cellType == "double" && i < currentField)
					{
						row.push_back(new DoubleObject(std::stod(cellContent)));
					}
					else if (cellType == "string" && i < currentField)
					{
						row.push_back(new StringObject(cellContent));
					}
				}
			}
			if (setup) {
				table->setTableName(tableName);
				table->setDatabaseName(databaseName);
				setup = false;
			}
			else if (table->getFieldCount() == 0)
			{
				table->setFields(&fieldTypes[0]);
				table->setFieldCount(currentField);

			}
			else if (table != nullptr)
				table->insert(&row[0]);
		}
		myfile.close();
	}
	else
		std::cout << "Unable to open file";
	tables.push_back(table);
	return table;
}

Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	Table* table = openTable(name);
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
