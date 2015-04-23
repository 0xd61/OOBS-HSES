#include "Parallelogramm.h"
#include <iostream>

using namespace std;


Parallelogramm::Parallelogramm()
{
}

Parallelogramm::Parallelogramm(const double a_value, const double b_value, const double winkel_value) : a(a_value), b(b_value), winkel(winkel_value)
{

}


Parallelogramm::~Parallelogramm()
{
}

void Parallelogramm::print()
{
	cout << "Seite a = " << a << "     Seite b = " << b << "     Winkel = " << winkel << endl;
}

void Parallelogramm::setA(const double a_value)
{
	a = a_value;
}

void Parallelogramm::setB(const double b_value)
{
	b = b_value;
}

void Parallelogramm::setWinkel(const double winkel_value)
{
	winkel = winkel_value;
}

double Parallelogramm::getA() const
{
	return(a);
}

double Parallelogramm::getB() const
{
	return(b);
}

double Parallelogramm::getWinkel() const
{
	return(winkel);
}