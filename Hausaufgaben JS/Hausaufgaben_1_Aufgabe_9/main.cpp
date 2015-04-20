#include <iostream>
using namespace std;

int f(int i) {
	cout << "Funktion 1: i=" << i << endl;
	return 0;
}

//Der Rückgabetyp zählt bei der überladung nicht als unterscheidung.
//void f(int i) { cout << "Funktion 2: i=" << i << endl; }

//char f(int i) {
//	cout << "Funktion 3: i=" << i << endl;
//	return 'a';
//}

//Parameterliste ist gleich wie f(int i), da für den Kompiler die Referenz als unterscheidung nicht zählt.
//int f(int & i) {
//	cout << "Funktion 4: i=" << i << endl;
//	return 1;
//}

int f(int i, int k) {
	cout << "Funktion 5: i=" << i << " k=" << k << endl;
	return 1;
}


int f(char c, int k) {
	cout << "Funktion 6: c=" << c << " k=" << k << endl;
	return 1;
}

//Funktions ist bereits definiert. Default Werte zählen nicht als unterscheidung.
//int f(int i, int k = 0) {
//	cout << "Funktion 7: i=" << i << " k=" << k << endl;
//	return 1;
//}

int f(double d, int i, char c = 'a') {
	cout << "Funktion 8: d=" << d << " i=" << i << " c=" << c << endl;
	return 1;
}

int f(double d, double e = 1.1, int i = 0) {
	cout << "Funktion 9: d=" << d << " e=" << e << " i=" << i << endl;
	return 1;
}

//Default Werte müssen ganz rechts in der Parameterliste stehen oder alle nachfolgenen Parameter müssen ebenfalls einen Default Wert haben.
//int f(double d, double e = 1.1, char c) {
//	cout << "Funktion 10: d=" << d << " e=" << e << " c=" << c << endl;
//	return 1;
//}

int f(char c, char d, int i = 2, char e = 'c') {
	cout << "Funktion 11: c=" << c << " d=" << d << " i=" << i << " e=" << e << endl;
	return 1;
}

int main(void)
{
	int i = 1;
	char c = 'a';
	f(1);			    // Ausgefuehrte Funktion: 
	f(c);			    // Ausgefuehrte Funktion:
	f(i);			    // Ausgefuehrte Funktion:
	c = f('a');		    // Ausgefuehrte Funktion:
	c = 'a';
	f(1, 2);		    // Ausgefuehrte Funktion:
	f(c, i);		    // Ausgefuehrte Funktion:
	f(1.0, 2.0);	    // Ausgefuehrte Funktion:
	f(1.0, 2.0, 1);	    // Ausgefuehrte Funktion:
	f(1.0, 1, 'a');	    // Ausgefuehrte Funktion:
	f(1.0, 1);		    // Ausgefuehrte Funktion:
	f(1.0, double(i));	// Ausgefuehrte Funktion:
	f(c, c, i);		    // Ausgefuehrte Funktion:
	f(c, i);			// Ausgefuehrte Funktion:
	return 0;
}

