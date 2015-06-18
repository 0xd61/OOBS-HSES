#include "DVD.hpp"
#include <iostream>

//Konstruktor
DVD::DVD(string t, string v, int j, int d) :Medium(t, v, j), dauer(d)
{}

// das Buch auf der Konsole ausgeben
void DVD::print() const
{
	Medium::print();
	std::cout << "Dauer:\t\t" << dauer << std::endl;
}