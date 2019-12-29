#ifndef TPOSE_H
#define TPOSE_H
#include "APlumbingElement.h"

class TPose : public virtual APlumbingElement
{
	bool isCorrectlyConnected(const IPlumbing* plumbing) const;
	TPose(int x, int y);
	~TPose();
};

#endif
