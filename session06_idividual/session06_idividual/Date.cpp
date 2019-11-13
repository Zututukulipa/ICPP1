#include "Date.h"

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date()
{
	this->_day = 0;
	this->_month = 0;
	this->_year = 0;
}

int Date::getYear() const
{
	return _year;
}

int Date::getMonth() const
{
	return _month;
}

int Date::getDay() const
{
	return _day;
}

void Date::setYear(int year)
{
	_year = year;
}

void Date::setMonth(int month)
{
	_month = month;
}

void Date::setDay(int day)
{
	_day = day;
}

//std::ostream& operator<<(std::ostream& stream, const Date& date)
//{
//	stream << date.getYear() << " " << date.getMonth() << " " << date.getDay();
//	return stream;
//}
//
//std::istream& operator>>(std::istream& stream, Date& date)
//{
//	int year, month, day;
//
//	stream >> year >> month >> day;
//
//	date.setYear(year);
//	date.setMonth(month);
//	date.setDay(day);
//
//	return stream;
//}


std::ostream& operator<<(std::ostream& stream, const Date& date)
{
	//stream << date.getYear() << " " << date.getMonth() << " " << date.getDay();
	int day = date.getDay();
	int month = date.getMonth();
	int year = date.getYear();
	stream.write((char*)&year, sizeof(year));
	stream.write((char*)&month, sizeof(month));
	stream.write((char*)&day, sizeof(day));



	return stream;
}

std::istream& operator>>(std::istream& stream, Date& date)
{
	int year, month, day;

	stream.read((char*)&year, sizeof(int));
	stream.read((char*)&month, sizeof(int));
	stream.read((char*)&day, sizeof(int));

	//stream >> year >> month >> day;

	date.setYear(year);
	date.setMonth(month);
	date.setDay(day);

	return stream;
}