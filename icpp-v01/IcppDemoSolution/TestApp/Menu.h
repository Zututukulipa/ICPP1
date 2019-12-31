#pragma once
#include "DbApi.h"

class Menu
{
private:
	Db* database = nullptr;
	Table* activeTable = nullptr;
	int option = -1;
	std::string dbname;
	std::string tablename;
	std::string stringLine;
	FieldObject** fieldTps = nullptr;
	std::ifstream myfile;
	Object** row = nullptr;
public:
	void render_menu();
	void readTable(const std::string& cs);
	std::vector<std::string> split(const std::string& str, const std::string& delim);
	std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str);
	void write_out_row(Table* tab, Object** row);
};

