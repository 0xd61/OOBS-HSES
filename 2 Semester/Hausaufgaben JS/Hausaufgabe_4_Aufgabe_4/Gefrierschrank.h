#pragma once
#include "Haushaltsgeraet.h"

class Gefrierschrank : virtual public Haushaltsgeraet
{
	public:
		Gefrierschrank();
		Gefrierschrank(const string name_value, const double gewicht_value, const double volumen_value);
		~Gefrierschrank();

		void print();

	public:
		void setVolumen(const double volumen_value);
		double getVolumen()const;

	protected:
		double volumen;

};

