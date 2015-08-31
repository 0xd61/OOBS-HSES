#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed     Scientific " << endl;

	for (int k = 1; k < 11; k++) {
		cout << setw(2) << setfill(' ') << right <<  dec << k;
		cout << setw(5) << showbase << setfill(' ') << oct << k;
		cout << setw(5) <<  hex << k << " ";
		cout << setw(7) << setfill('+') << right << string(k % 5 + 1, '*') << " ";
		cout << setw(10) << setfill(' ') << showpos << left <<  setprecision(3) << fixed << d;
		cout << setw(12) << noshowpos <<  scientific << d;
		d = d*-2;
		cout << endl;
	}
	return 0;
}
