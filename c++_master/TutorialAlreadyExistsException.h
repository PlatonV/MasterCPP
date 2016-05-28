#pragma once

#include <iostream>
#include <exception>

class TutorialAlreadyExistsException : public std::exception
{
public:
	virtual const char * what() const throw()
	{
		return "Tutorial already exists!";
	}
};
