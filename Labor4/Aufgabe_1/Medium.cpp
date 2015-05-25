#include "Medium.hpp"
#include <iostream>

// Konstruktor
Medium::Medium(string t, string v, int j, string typ) :titel(t), verlag(v), jahr(j), typ(typ)
{}
// Titel zurückliefern
string Medium::getTitel() const
{
	return titel;
}
// Typ zurückliefern
string Medium::getTyp() const
{
	return typ;
}
// Ausleiher zurückliefern
Person * Medium::getAusleiher() const
{
	return ausleiher;
}
// das Mediuem "ausleihen", d.h. Person p, von und bis eintragen
void Medium::ausleihen(Person & p, Datum von, Datum bis)
{
	ausleiher = &p;
	this->von = von;
	this->bis = bis;

}
// Medium in der Konsole ausgeben
void Medium::print() const
{
	std::cout << "-----------------------------------------" << endl;
	std::cout << typ << std::endl;
	std::cout << "Titel:\t\t" << titel << std::endl;
	std::cout << "Verlag:\t\t" << verlag << std::endl;
	std::cout << "Jahr:\t\t" << jahr << std::endl;
	std::cout << "Ausleiher:\t";
	if (ausleiher)
	{
		ausleiher->print();
		std::cout << " von: " << von << " bis: " << bis << endl;
	}
	else
		std::cout << "kein";
	std::cout << std::endl;
}