#include "Bibliothek.hpp"
#include <iostream>

//Konstruktor
Bibliothek::Bibliothek(int maxAnzahl) :maxAnz(maxAnzahl)
{
	medien = new Medium*[maxAnz];
	anz = 0;
}

Bibliothek::~Bibliothek()
{
		delete[] medien;
}

// Kopie eines Buches in den Katalog der Bibliothek eintragen
void Bibliothek::mediumBeschaffen(Buch & buch)
{
	medien[anz] = &buch;
	anz++;
}
// Kopie einer DVD in den Katalog der Bibliothek eintragen
void Bibliothek::mediumBeschaffen(DVD & dvd)
{
	medien[anz] = &dvd;
	anz++;
}
// alle Medien auf der Konsole ausgeben, 
// die im Titel das Suchwort enthalten
void Bibliothek::mediumSuchen(string suchwort)
{
	std::cout << "\nSuche nach \"" << suchwort << "\". Ergebnis:" << std::endl;
	for (int i=0; i < anz; i++)
	{
		if (medien[i]->getTitel().find(suchwort) != std::string::npos)
		{
			std::cout << "\nMedium " << i  << std::endl;
			medien[i]->print();
		}
			
	}
}
// im Medium mit der Nummer nr, die Person p als Ausleiher
// eintragen mit von-Datum d und bis-Datum d+p.ausleihdauer
void Bibliothek::mediumAusleihen(int nr, Person & p, Datum d)
{
	medien[nr]->ausleihen(p,d, d + p.getAusleihdauer());
}
// alle Medien in der Konsole ausgeben
void Bibliothek::print() const
{
	std::cout << "\nBibliothekskatalog:" << std::endl;
	for (int i = 0; i < anz; i++)
	{
		medien[i]->print();
	}
}


