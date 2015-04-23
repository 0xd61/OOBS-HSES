#include "Elektrogeraet.h"
#include <iostream>

using namespace std;


Elektrogeraet::Elektrogeraet()
{
}

Elektrogeraet::Elektrogeraet(const unsigned int watt_value) : watt(watt_value)
{

}

Elektrogeraet::~Elektrogeraet()
{
}

void Elektrogeraet::print()
{
	cout << "Leistungsaufnahme: " << watt << " W" << endl;
}

void Elektrogeraet::setWatt(const unsigned int watt_value)
{
	watt = watt_value;
}

unsigned int Elektrogeraet::getWatt() const
{
	return(watt);
}