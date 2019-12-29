#ifndef DRAIN_H
#define DRAIN_H
#include "APlumbingElement.h"

class Drain : public virtual APlumbingElement
{
	bool isCorrectlyConnected(const IPlumbing* plumbing) const;
	Drain(int x, int y);
	~Drain();
};

#endif
