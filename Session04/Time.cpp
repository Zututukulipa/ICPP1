#ifndef TIME_H
#include "Time.h"
#include "Err.h"
Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::~Time()
{
}
int getSecondsFromTimeStamp(const Time* timestamp) {
	return timestamp->getHours() * 3600 + timestamp->getMinutes() * 60 + timestamp->getSeconds();
}

int Time::compareTo(IComparable* objComparedTo) const
{
	Time* time = dynamic_cast<Time*>(objComparedTo);
	if (time != nullptr) {
		auto compHours = time->getHours();
		auto compMins = time->getMinutes();
		auto compSecs = time->getSeconds();
		auto currentSum = getSecondsFromTimeStamp(this);
		auto comparedSum = getSecondsFromTimeStamp(time);

		if (currentSum > comparedSum)
			return 1;
		else if (currentSum < comparedSum)
			return -1;

		return 0;

	}
	throw Err("an error has occured");
}



void Time::sortField(IComparable** array, int arraySize) {
	int i, j;
	for (i = 0; i < arraySize - 1; i++)
		// Last i elements are already in place  
		for (j = 0; j < arraySize - i - 1; j++)
			if (array[j] > array[j + 1]) {
				auto switchedTime = array[i];
				array[i] = array[i + 1];
				array[i + 1] = switchedTime;
			}
}

std::string Time::ToString()
{
	return std::to_string(this->getHours()) + "h " + std::to_string(this->getMinutes()) + "m " + std::to_string(this->getSeconds()) + "s ";
}

int Time::getSeconds() const
{
	return seconds;
}
int Time::getMinutes() const
{
	return minutes;
}
int Time::getHours() const
{
	return hours;
}

#endif TIME_H