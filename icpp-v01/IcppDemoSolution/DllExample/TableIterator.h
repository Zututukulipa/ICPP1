#ifndef TABLEITERATOR_H
#define TABLEITERATOR_H

#include "DbApi.h";

class TableIterator : public Iterator
{
	bool moveNext() override;
	Object** getRow() override;
	int getRowId() override;
	void close() override;

	
};

#endif // !TABLEITERATOR_H
