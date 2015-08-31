#include "ObjectCounter.h"
#include <iostream>

using namespace std;

int main()
{
	ObjectCounter o1;
	ObjectCounter o2;
	ObjectCounter o3;
	ObjectCounter o4;

	cout << "Anzahl Objekte: " << o4.getNumber() << endl;
	cout << "Höchste ID: " << o4.getMaxId() << endl;

	return(0);
}