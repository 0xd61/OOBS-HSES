#pragma once
#include "Haushaltsgeraet.h"

class Gefrierschrank : public Haushaltsgeraet
{
	public:
		Gefrierschrank(const string name_value, const double gewicht_value, const double volumen_value);
		~Gefrierschrank();

		void print();

	public:
		void setVolumen(const double volumen_value);

	private:
		double volumen;

};

