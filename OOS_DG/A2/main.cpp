#include <iostream>

using namespace std;

int main()
{
	int numInt;
	float Durchschnitt = 0.0f;
	cout << "Wie viele Integerzahlen sollen eingegeben werden: ";
	cin >> numInt;

	int * pArr = new int[numInt];

	cout << "Bitte " << numInt << " Zahlen eingeben (Zahl mit Return bestaetigen)" << endl;
	for (int i = 0; i < numInt; i++)
		cin >> pArr[i];
	
	cout << "Zahlen im Array: ";
	for (int i = 0; i < numInt; i++)
	{
		cout << pArr[i] << "; ";
		Durchschnitt += pArr[i];
	}

    cout << endl << "Durchschnitt = " << (Durchschnitt /= numInt);

	fflush(stdin);
	getchar();
	return 0;
}