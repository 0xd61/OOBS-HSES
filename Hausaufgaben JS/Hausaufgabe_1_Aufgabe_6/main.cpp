#include <iostream>
using namespace std;

int main(void)
{
	int i = 1; 
	int & j = i; //j ist alias für i.
	int * ptr;
	ptr = &i; //ptr zeigt auf j und i.

	cout << "Groesse von i: " << sizeof(i) << endl; //Ausgabe 4.
	cout << "Groesse von j: " << sizeof(j) << endl; //Ausgabe 4.
	cout << "Groesse von ptr: " << sizeof(ptr) << endl; //Ausgabe 4.
	cout << boolalpha; //Ausgabe auf true und false setzten für bools.
	cout << "Die Adressen von i und j sind gleich: ";
	cout << (&i == &j) << endl; //true, da j alias für i ist.
	cout << "Die Adressen von j und *ptr sind gleich: ";
	cout << (&j == &(*ptr)) << endl;//true, da ptr auf i zeigt und j alias für i ist.
	cout << "Die Adressen von j und ptr sind gleich: ";
	cout << (int(&j) == int(&ptr)) << endl; 
	//false, da mit den Addressen vond j und ptr zwei neue int erzeugt werden, allerdings ist die Adresse der ptr Variable und nicht
	//die Addresse von i.
	
	return 0;
}
