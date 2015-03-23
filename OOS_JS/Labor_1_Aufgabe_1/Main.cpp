#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed     Scientific " << endl;

	for (int k = 1; k < 11; k++) {
		cout << setw(2) << setfill(' ') << right <<  dec << k;
		cout << setw(3) << setfill(' ') << oct << k;
		cout << setw(3) << "    0x" << hex << k << " ";
		cout << setw(7) << setfill('+') << left << string(k % 5 + 1, '*') << " ";
		cout << setw(2) <<  setprecision(3) << fixed << d;
		cout << "    " << scientific << d;
		d = d*-2;
		cout << endl;
	}
	return 0;
}
