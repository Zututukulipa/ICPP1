#ifndef EASTWEST_H
#define EASTWEST_H
#include "APlumbingElement.h"

class EastWest : public virtual APlumbingElement
{
	bool isCorrectlyConnected(const IPlumbing* plumbing) const;
	EastWest(int x, int y);
	~EastWest();
};

#endif
