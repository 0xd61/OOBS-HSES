#include "Kombination.h"
#include <iostream>

using namespace std;

Kombination::Kombination()
{
}

Kombination::Kombination(const string name_value, const double gewicht_value, const double volumen_gs, const double volumen_ks) : Haushaltsgeraet(name_value, gewicht_value)
{
	Kuehlschrank::volumen = volumen_ks;
	Gefrierschrank::volumen = volumen_gs;
}


Kombination::~Kombination()
{
}

void Kombination::print()
{
	Haushaltsgeraet::print();
	cout << "Gefriervolumen = " << Gefrierschrank::volumen << " L" << endl;
	cout << "Kuehlvolumen = " << Kuehlschrank::volumen << " L" << endl;
}
