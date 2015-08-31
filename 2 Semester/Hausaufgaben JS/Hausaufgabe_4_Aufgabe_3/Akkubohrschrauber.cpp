#include "Akkubohrschrauber.h"
#include <iostream>

using namespace std;

Akkubohrschrauber::Akkubohrschrauber()
{
}

Akkubohrschrauber::Akkubohrschrauber(const unsigned int wattBohrer_value, const unsigned int wattSchrauber_value) : Akkubohrer(wattBohrer_value), Akkuschrauber(wattSchrauber_value)
{

}

Akkubohrschrauber::~Akkubohrschrauber()
{
}

void Akkubohrschrauber::print()
{
	cout << "Bohrer: ";
	Akkubohrer::print();

	cout << "Schrauber: ";
	Akkuschrauber::print();
}
