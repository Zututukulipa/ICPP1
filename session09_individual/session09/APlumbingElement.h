#ifndef APLUMBING_ELEMENT_H
#define APLUMBING_ELEMENT_H
#include "IPlumbing.h"


class IPlumbing;
class APlumbingElement
{
protected:
	int _x, _y;
public:
	virtual ~APlumbingElement(){}
	virtual bool isCorrectlyConnected(const IPlumbing* plumbing) const = 0;
};

#endif
