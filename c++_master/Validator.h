#pragma once

#include "master.h"

class Validator
{
public:
	Validator() {};

	static bool ValidateTutorial(const Tutorial& _t, vector<Tutorial*> v)
	{
		for (Tutorial *t : v)
		{
			if (_t == *t)
			{
				return false;
			}
		}
		return true;
	}
};

