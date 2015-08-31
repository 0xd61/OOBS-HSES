#pragma once
#include "Haushaltsgeraet.h"

class Kuehlschrank : virtual public Haushaltsgeraet
{
	public:
		Kuehlschrank();
		Kuehlschrank(const string name_value, const double gewicht_value, const double volumen_value);
		~Kuehlschrank();
		void print();

	public:
		void setVolumen(const double volumen_value);
		double getVolumen()const;

	protected:
		double volumen;
};

