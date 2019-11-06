#pragma once
#include <iostream>
class Date
{
private:
	int _day, _month, _year;
public:
	Date(int day, int month, int year);
	Date();
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	void setYear(int);
	void setMonth(int);
	void setDay(int);
};

std::ostream& operator<<(std::ostream&, const Date&);
std::istream& operator>>(std::istream&, Date&);