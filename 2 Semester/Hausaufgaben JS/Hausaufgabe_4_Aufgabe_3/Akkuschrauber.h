#pragma once
#include "Elektrogeraet.h"

class Akkuschrauber : public Elektrogeraet
{
	public:
		Akkuschrauber();
		Akkuschrauber(const unsigned int watt_value);
		~Akkuschrauber();
};

