#include "Buch.hpp"
#include <iostream>

//Konstruktor
Buch::Buch(string t, string a, string v, int jahr) :Medium(t, v, jahr,"Buch"), autor(a)
{}

// das Buch auf der Konsole ausgeben
void Buch::print() const
{
	Medium::print();
	std::cout << "Autor:\t\t" << autor << std::endl;
}
