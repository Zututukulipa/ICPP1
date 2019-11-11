#include <iostream>
#include <random>
#include <exception>
#include "Time.h"

int main() {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> hours(0, 24);
	std::uniform_int_distribution<> rest(0, 59);
	Time** arr = new Time * [10];

	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = new Time(hours(eng), rest(eng), rest(eng));
		std::cout << arr[i]->ToString() << std::endl;
	}

	try
	{
		for (size_t i = 0; i < 9; i++)
		{
			std::cout << arr[i]->ToString() + "VS " + arr[i+1]->ToString() << std::endl;
			switch (arr[i]->compareTo(arr[i+1]))
			{
			case 0: 
				std::cout << "Casy se rovnaji" << std::endl;
				break;
			default:
				std::cout << "Casy se nerovnaji" << std::endl;
				break;
			}
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		delete arr[i];
	}

	delete[] arr;
    return 0;
}