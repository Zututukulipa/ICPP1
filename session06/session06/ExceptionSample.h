#pragma once
#ifndef EXCEPTIONSAMPLE_H
#include <stdexcept>
#include <iostream>

void ThrowExceptionFunction()
{
	//throw new std::exception("Generic Exception");
	throw std::exception("Generic Exception");
}

void HandleExceptionFunction()
{
	try {
		ThrowExceptionFunction();
	}
		//catch (std::exception e)
		//catch (std::exception & e)
		catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
		throw;
	}
}

#endif // !EXCEPTIONSAMPLE_H
