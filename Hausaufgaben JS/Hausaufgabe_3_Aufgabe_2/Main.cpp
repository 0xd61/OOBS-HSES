#include "Kunde.h"

int main()
{
	Kunde *k1 = new Kunde("Gordon", "Esslingen", new int(25));
	Kunde *k2 = new Kunde("Guybrush", "Stuttgart", new int(30));
	Kunde *k3 = new Kunde(k2);

	k1->kaufe(50);
	k1->kaufe(50);

	k2->kaufe(10);
	k3->kaufe(5);
	k3->kaufe(10);

	k1->print();
	k2->print();
	k3->print();

	return(0);
}