#include "TableIterator.h"
#include <iostream>


TableIterator::~TableIterator()
{
	TableIterator::close();
}

bool TableIterator::moveNext()
{
	return row_count > 0 && currentRow < row_count;
}

Object** TableIterator::getRow()
{
	return rows[currentRow++];
}

int TableIterator::getRowId()
{
	return currentRow;
}

void TableIterator::close()
{
	for (int i = 0; i < field_count; ++i) {
		delete[] rows[i];
	}
	delete[] rows;
	std::cout << "Iterator closed." << std::endl;
}

TableIterator::TableIterator(Object*** rows, int row_count, int field_count)
{
	this->rows = rows;
	this->row_count = row_count;
	this->field_count = field_count;
	currentRow = 0;
}


