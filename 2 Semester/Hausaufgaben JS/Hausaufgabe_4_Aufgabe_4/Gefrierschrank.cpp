#include "Gefrierschrank.h"
#include <iostream>

Gefrierschrank::Gefrierschrank()
{

}

Gefrierschrank::Gefrierschrank(const string name_value, const double gewicht_value, const double volumen_value) : Haushaltsgeraet(name_value, gewicht_value), volumen(volumen_value)
{
}


Gefrierschrank::~Gefrierschrank()
{
}

void Gefrierschrank::print()
{
	Haushaltsgeraet::print();
	cout << "Volumen = " << volumen << " L" << endl;
}

void Gefrierschrank::setVolumen(const double volumen_value)
{
	volumen = volumen_value;
}

double Gefrierschrank::getVolumen()const
{
	return(volumen);
}
