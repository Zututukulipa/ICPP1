#ifndef TABLEITERATOR_H
#define TABLEITERATOR_H

#include "DbApi.h"

class TableIterator : public Iterator
{
private:
	int currentRow;
	Object*** rows;
	int row_count;
	int field_count;
public:
	~TableIterator();
	bool moveNext() override;
	Object** getRow() override;
	int getRowId() override;
	void close() override;
	TableIterator(Object*** rows, int row_count, int field_count);
};


#endif // !TABLEITERATOR_H
