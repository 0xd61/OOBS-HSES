#pragma once
#include "Akkubohrer.h"
#include "Akkuschrauber.h"

class Akkubohrschrauber : public Akkubohrer, public Akkuschrauber
{
	public:
		Akkubohrschrauber();
		Akkubohrschrauber(const unsigned int wattBohrer_value, const unsigned int wattSchrauber_value);
		~Akkubohrschrauber();

		void print();
};

