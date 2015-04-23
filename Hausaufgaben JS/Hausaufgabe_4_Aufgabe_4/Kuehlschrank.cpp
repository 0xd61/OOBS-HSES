#include "Kuehlschrank.h"
#include <iostream>

using namespace std;

Kuehlschrank::Kuehlschrank()
{

}

Kuehlschrank::Kuehlschrank(const string name_value, const double gewicht_value, const double volumen_value) : Haushaltsgeraet(name_value, gewicht_value), volumen(volumen_value)
{
}



Kuehlschrank::~Kuehlschrank()
{
}


void Kuehlschrank::print()
{
	Haushaltsgeraet::print();
	cout << "Volumen = " << volumen << " L" << endl;
}

void Kuehlschrank::setVolumen(const double volumen_value)
{
	volumen = volumen_value;
}

double Kuehlschrank::getVolumen()const
{
	return(volumen);
}