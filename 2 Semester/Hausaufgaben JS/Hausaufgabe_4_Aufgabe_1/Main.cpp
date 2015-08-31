#include "Gefrierschrank.h"
#include <iostream>

int main()
{
	Haushaltsgeraet h1 = Haushaltsgeraet("Haushaltsgeraet Nr 1", 7.1);
	Gefrierschrank h2 = Gefrierschrank("Gefrierschrank Nr 1", 21.5, 101);

	h1.print();
	cout << endl;
	h2.print();

	h2.setGewicht(10);
	h2.setVolumen(1000);

	cout << endl;
	h2.print();

	return(0);
}