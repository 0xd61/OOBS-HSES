#include <iostream>

using namespace std;

int main()
{
	unsigned int numberOfInputs = 0;
	int average = 0;
	int *dynArray = nullptr;

	cout << "Wie viele Zahlen sollen eingelesen werden?   Eingabe: ";
	cin >> dec >> numberOfInputs;
	cout << endl;

	dynArray = new int[numberOfInputs];

	for (int i = 0; i < numberOfInputs; i++)
	{
		cout << (i+1) << ". Zahl eingeben: ";
		cin >> dynArray[i];
	}

	cout << endl <<  "Eingegebene Zahlen:" << endl;
	for (int i = 0; i < numberOfInputs;i++)
	{
		average += dynArray[i];
		cout << dynArray[i] << " ";
	}

	cout << endl << endl << "Durchschnitt aller Zahlen: " << average / float(numberOfInputs) << endl << endl;

	delete[] dynArray;
	dynArray = nullptr;

	return(0);
}