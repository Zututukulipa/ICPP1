#ifndef PLUMBING_H
#define PLUMBING_H

#include <string>
#include "IPlumbing.h"
#include "APlumbingElement.h"

APlumbingElement;
class Plumbing : public virtual IPlumbing {
private:
	APlumbingElement*** elementField;
	int width, height;

public:

	~Plumbing() {}
	Plumbing(std::string plumbing_path);
	virtual const APlumbingElement* GetElement(int x, int y) const;
	virtual bool IsPlumbingOk() const;

};

#endif
