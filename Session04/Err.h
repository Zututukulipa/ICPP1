#ifndef ERR_H
#include <exception>
#include <iostream>
#include <string>

class Err : public std::exception
{
	std::string _msg;
public:
	Err(const std::string& msg) : _msg(msg) {}

	virtual const char* what() const noexcept override
	{
		return _msg.c_str();
	}
};
#endif ERR_H