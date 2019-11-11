#include <iostream>
class IObject
{
private:
public:
	IObject() {};
	virtual ~IObject() {};
    virtual std::string ToString()=0;
};
