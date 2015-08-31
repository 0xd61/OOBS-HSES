#include "Fahrzeug.h"
#include <iostream>
using namespace std;

int Fahrzeug::zaehler = 0;

int main() 
{
	Fahrzeug f1("ES - H 123");
	cout << f1 << endl;
	f1.fahren(101.5);
	cout << f1 << endl;
	Fahrzeug f2("ES - M 4711");
	f2.fahren(10.57);
	cout << f2 << endl;

	cout << "Gesamt Kilometerstand: " << Fahrzeug::getSummeKm() << endl << endl;

	{
		Fahrzeug f3("KA - M 1337");
		f3.fahren(100);
		cout << f3 << endl;
		cout << "Gesamt Kilometerstand: " << Fahrzeug::getSummeKm() << endl << endl;
	}

	cout << "Fahrzeug f3 hat den Fuhrpark verlassen" << endl;
	cout << "Gesamt Kilometerstand: " << Fahrzeug::getSummeKm() << endl;

	return 0;
}
