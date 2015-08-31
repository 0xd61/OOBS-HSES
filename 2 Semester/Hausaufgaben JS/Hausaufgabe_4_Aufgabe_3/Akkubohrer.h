#pragma once
#include "Elektrogeraet.h"

class Akkubohrer : public Elektrogeraet
{
	public:
		Akkubohrer();
		Akkubohrer(const unsigned int watt_value);
		~Akkubohrer();
};

