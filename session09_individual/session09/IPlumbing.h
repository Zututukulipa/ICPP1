#ifndef IPLUMBING_H
#define IPLUMBING_H

#include "APlumbingElement.h"

class APlumbingElement;
class IPlumbing
{
public:
	virtual ~IPlumbing() {}
	virtual const APlumbingElement *GetElement(int x, int y) const = 0;
	virtual bool IsPlumbingOk() const = 0;
};


#endif

