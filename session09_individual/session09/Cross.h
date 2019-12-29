#ifndef CROSS_H
#define CROSS_H
#include "APlumbingElement.h"

class Cross : public virtual APlumbingElement
{
	bool isCorrectlyConnected(const IPlumbing* plumbing) const;
	Cross(int x, int y);
	~Cross();
};

#endif
