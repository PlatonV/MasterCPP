#pragma once

#include <iostream>
#include <exception>

class TutorialNotFoundException : public std::exception
{
public:
	virtual const char * what() const throw()
	{
		return "Tutorial not found!";
	}
};
