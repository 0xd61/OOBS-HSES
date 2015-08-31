#include <string>
#include <iomanip>
#include <iostream> 
using namespace std;

int main() {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++) {
		cout << setw(3) << nouppercase << dec << k;
		cout << setw(4) << showbase << oct << k;
		cout << setw(5) <<  hex  << k << " ";
		cout << setw(7) << left << setfill('+') << string(k % 5 + 1, '*') << " ";
		cout << setfill(' ') << setw(9) << showpos << right << fixed << setprecision(3) << d;
		cout << setw(12) << uppercase << noshowpos << scientific << d;
		d = d*-2;
		cout << endl;
	}
	system("pause");
	return 0;
}
