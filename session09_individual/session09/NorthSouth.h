#ifndef NORTHSOUTH_H
#define NORTHSOUTH_H
#include "APlumbingElement.h"

class NorthSouth : public virtual APlumbingElement
{
	bool isCorrectlyConnected(const IPlumbing* plumbing) const;
	NorthSouth(int x, int y);
	~NorthSouth();
};

#endif
