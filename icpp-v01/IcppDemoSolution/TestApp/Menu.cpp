#include "Menu.h"
#include <iostream>
#include <sstream>

void Menu::render_menu()
{
	std::cout << "~FlOw~"
		<< std::endl << "OpTiOnS:"
		<< std::endl << "1\tOpen Database"
		<< std::endl << "2\tOpen Table"
		<< std::endl << "3\tOpen/Create Table"
		<< std::endl << "4\tAdd Row"
		<< std::endl << "5\tDelete Row"
		<< std::endl << "6\tUpdate Row"
		<< std::endl << "7\tDisplay Tables"
		<< std::endl << "8\tDisplay Saved Table Content"
		<< std::endl << "9\tCommit Table"
		<< std::endl << "Enter Option:"
		<< std::endl << ">";
	std::cin >> option;
	int fieldCount = -1;
	switch (option)
	{
	case 1:
		std::cout << "Enter Database name: " << std::endl;
		std::cin >> dbname;
		database = Db::open(dbname);
		break;
	case 2:
		if (database != nullptr)
		{
			std::cout << "Enter Table name: " << std::endl;
			std::cin >> tablename;
			activeTable = database->openTable(tablename);
			if (activeTable != nullptr)
				std::cout << "Table Opened." << std::endl;
			else
				std::cout << "Table Not Found." << std::endl;
		}
		else
		{
			std::cout << "First open database" << std::endl;
		}
		break;
	case 3:
		if (database != nullptr)
		{
			std::cout << "Enter Table name: " << std::endl;
			std::cin >> tablename;
			std::cout << "If not found:" << std::endl;
			std::cout << "\tProvide field count:" << std::endl;
			std::cin >> fieldCount;
			fieldTps = new FieldObject * [fieldCount];
			for (int i = 0; i < fieldCount; ++i)
			{
				std::cout << "\tProvide field type[" << i << "]" << std::endl;
				std::cout << "\t\t1. Integer" << std::endl;
				std::cout << "\t\t2. Double" << std::endl;
				std::cout << "\t\t3. String" << std::endl;
				std::cin >> option;
				if (option > 0 && option < 4)
				{
					std::cout << "Enter Field Name:" << std::endl;
					std::cin >> stringLine;
					switch (option)
					{
					case 1:
						fieldTps[i] = new FieldObject(stringLine, FieldType::Integer);
						break;
					case 2:
						fieldTps[i] = new FieldObject(stringLine, FieldType::Double);
						break;
					case 3:
						fieldTps[i] = new FieldObject(stringLine, FieldType::String);
						break;
					default: break;
					}
				}
				else
				{
					std::cout << "Incorrect option." << std::endl;
					break;
				}
			}
			if (fieldTps[0] != nullptr)
				activeTable = database->openOrCreateTable(tablename, fieldCount, fieldTps);
		}

		else
		{
			std::cout << "First open database" << std::endl;
		}
		break;
	case 4:
		if (activeTable == nullptr)
		{
			std::cout << "First open a table." << std::endl;
			break;
		}
		row = new Object * [activeTable->getFieldCount()];
		for (int i = 0; i < activeTable->getFieldCount(); ++i)
		{
			int iValue = 0;
			double dValue = 0;
			std::string sValue;
			char type = 'n';
			switch (activeTable->getFields()[i]->type)
			{
			case FieldType::Integer:
				type = 'i';
				std::cout << activeTable->getFields()[i]->name << " [INTEGER]" << std::endl << "Enter Value:" << std
					::
					endl;
				std::cin >> iValue;
				row[i] = Db::Int(iValue);
				break;
			case FieldType::Double:
				type = 'd';
				std::cout << activeTable->getFields()[i]->name << " [DOUBLE]" << std::endl << "Enter Value:" << std
					::
					endl;
				std::cin >> dValue;
				row[i] = Db::Double(dValue);
				break;
			case FieldType::String:
				type = 's';
				std::cout << activeTable->getFields()[i]->name << " [STRING]" << std::endl << "Enter Value:" << std
					::
					endl;
				std::cin >> sValue;
				row[i] = Db::String(sValue);
				break;
			default: break;
			}
		}
		activeTable->insert(row);
		std::cout << "Row added." << std::endl;
		break;
	case 5:
		if (activeTable != nullptr) {
			std::cout << "Enter Row ID:" << std::endl;
			std::cin >> option;
			activeTable->remove(option);
			std::cout << "Row removed" << std::endl;
		}else
		{
			std::cout << "Open a Table first" << std::endl;
		}
		break;
	case 6:
		break;
	case 7:
		if (database != nullptr) {
			myfile.open(database->getDatabaseName() + ".txt");
			if (myfile.is_open())
			{
				while (getline(myfile, stringLine))
				{
					std::cout << stringLine << std::endl;
					stringLine.clear();
				}
				myfile.close();
			}
		}
		else
		{
			std::cout << "First open a Database" << std::endl;
		}
		
		break;
	case 8:
		if (database != nullptr) {

		myfile.open(database->getDatabaseName() + ".txt");
		if (myfile.is_open())
		{
			while (getline(myfile, stringLine))
			{
				readTable(stringLine);
				stringLine.clear();
			}
			myfile.close();
		}
		}
		else
		{
			std::cout << "First open a Database" << std::endl;
		}
		break;
	case 9:
		if (activeTable != nullptr)
			activeTable->commit();
		break;
	default:
		if(activeTable != nullptr)
			activeTable->close();
		if(database != nullptr)
			database->close();
		exit(0);
	}
}

void Menu::readTable(const std::string& cs)
{
	std::ifstream myfile;
	std::string cellType;
	std::string cellContent;
	int currentField = 0;
	myfile.open(cs + ".txt", std::ios::in);
	std::cout << cs << std::endl << "=================================================================================================" << std::endl;
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
				if (cellType == "field")
				{
					if (cellContent == "int")
						std::cout << splitField[2] << " [INTEGER]\t";
					else if (cellContent == "double")
						std::cout << splitField[2] << " [DOUBLE]\t";
					else if (cellContent == "string")
						std::cout << splitField[2] << " [STRING]\t";
					else if (cellContent == "key")
						std::cout << splitField[2] << " [FK]\t";
					++currentField;
				}
				else
				{
					std::cout << "|" <<splitField[0] << "|" << "\t";
				}
			}
			std::cout << std::endl;
		}
		myfile.close();
		std::cout << std::endl << "=================================================================================================" << std::endl;

	}
	else
		std::cout << "Unable to open file";
}

std::vector<std::string> Menu::split(const std::string& str, const std::string& delim)
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
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

std::vector<std::string> Menu::getNextLineAndSplitIntoTokens(std::istream& str)
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

void Menu::write_out_row(Table* tab, Object** row)
{
	for (int i = 0; i < tab->getFieldCount(); ++i)
	{
		if (row[i] != nullptr)
		{
			if ((FieldObject*)row[i]->isType(FieldType::Integer))
			{
				std::cout << static_cast<IntObject*>(row[i])->value << "\t";
			}
			else if ((FieldObject*)row[i]->isType(FieldType::Double))
			{
				std::cout << static_cast<IntObject*>(row[i])->value << "\t";
			}
			else if ((FieldObject*)row[i]->isType(FieldType::String))
			{
				std::cout << static_cast<IntObject*>(row[i])->value << "\t";
			}
		}
		else
		{
			std::cout << "|_NULL_|" << std::endl;
		}
	}
}
