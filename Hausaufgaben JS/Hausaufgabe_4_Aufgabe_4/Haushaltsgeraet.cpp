#include "Haushaltsgeraet.h"
#include <iostream>


Haushaltsgeraet::Haushaltsgeraet()
{

}


Haushaltsgeraet::Haushaltsgeraet(const string name_value, const double gewicht_value) : gewicht(gewicht_value), name(name_value)
{

}


Haushaltsgeraet::~Haushaltsgeraet()
{
}

void Haushaltsgeraet::print()
{
	cout << "Geraetename = " << name << endl;
	cout << "Gewicht = " << gewicht << " kg" << endl;
}

void Haushaltsgeraet::setGewicht(const double gewicht_value)
{
	gewicht = gewicht_value;
}

double Haushaltsgeraet::getGewicht() const
{
	return(gewicht);
}

string Haushaltsgeraet::getName() const
{
	return(name);
}