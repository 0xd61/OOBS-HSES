#include <iostream>
#include "Fifo.h"

using namespace std;

int main()
{
	//ZUR UEBERSICHT STEHEN DIE COUT UNTEREINANDER!
	Fifo Nr1;
	cout << "Test leerer Fifo: " << Nr1.pop() << endl;
	cout << "Push: ";
	cout << Nr1.push('D'); //0
	cout << Nr1.push('a'); //1
	cout << Nr1.push('n') << endl; //2

	cout << "Pop: ";
	cout << Nr1.pop(); //D
	cout << Nr1.pop() << endl; //a

	cout << "Push: " << Nr1.push(' '); //3
	cout << Nr1.push('J'); //4
	cout << Nr1.push('o') << endl; //5

	cout << "Pop: ";
	cout << Nr1.pop(); //n
	cout << Nr1.pop(); // ' '
	cout << Nr1.pop(); //J
	cout << Nr1.pop(); //o
	cout << Nr1.pop() << endl << endl; //
	
	Fifo Nr2(2);
	cout << "Test, wenn Fifo voll: " << Nr2.push('R'); //0
	cout << Nr2.push('E'); //1
	cout << Nr2.push('L'); //-1
	cout << Nr2.pop(); //R
	cout << Nr2.push('%'); //0
	cout << Nr2.pop(); //E
	cout << Nr2.pop(); //%


	getchar();
	return 0;
}