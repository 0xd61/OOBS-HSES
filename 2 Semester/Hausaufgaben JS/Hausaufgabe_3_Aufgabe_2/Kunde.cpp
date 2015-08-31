#define _CRT_SECURE_NO_WARNINGS
#include "Kunde.h"
#include <string>
#include <iostream>

using namespace std;

int Kunde::anzahl = 0;

Kunde::Kunde(char *Name, char *Ort, int *Alter) : name(Name), ort(Ort), alter(Alter), umsatz(0), id(anzahl)
{
	anzahl++;
}

Kunde::Kunde(const Kunde* kunde)
{
	*this = *kunde;
	id = anzahl;
	anzahl++;

}

void Kunde::kaufe(double u)
{
	umsatz += u;
	transaktion++;
}

int Kunde::getAnzahl()
{
	return(anzahl);
}

void Kunde::print()
{
	cout << "Kunde " << name << " aus " << ort << "(ID = " << id << ", " << *alter << " Jahre)" << " hatte " << transaktion << " Transaktion(en) und " << umsatz << " Euro Umsatz" << endl << endl << endl;
}

Kunde::~Kunde()
{
	delete alter;
	alter = nullptr;

	delete ort;
	ort = nullptr;

	delete name;
	name = nullptr;
}
