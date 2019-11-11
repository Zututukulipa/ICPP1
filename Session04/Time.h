#ifndef I_COMPARABLE_H
#include "IComparable.h"
#include "IObject.h"
class Time: public IComparable, IObject
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    Time(int hours, int minutes, int seconds);
    ~Time();
    int compareTo(IComparable* obj) const override;
    void sortField(IComparable** array, int arraySize);
	std::string ToString() override;
};
#endif //!I_COMPARABLE_H