#include <iostream>

using namespace std;


#define ARRAY_SIZE 5

int main()
{
	//Local auf Deutsch setzten um Umlaute auszugeben.
	setlocale(LC_ALL, "");


	int iArray[ARRAY_SIZE];

	//Zahlen einlesen.
	cout << ARRAY_SIZE << " ganz Zahlen eingeben:" << endl;
	for (int & value : iArray)
	{
		cin  >> value;
	}
		
	//Zahlen erhöhen.
	cout<< endl << "Zahlen um 1 erhöhen und Ausgeben:"  << endl;
	for (int &  value : iArray)
	{
		value++;
		cout <<  value << endl;
	}

	//Durchschnitt berechnen und ausgeben.
	int arrayAverage = 0;
	cout << endl << "Durchschnitt berechnen und Ausgeben:" << endl;
	for (int  value : iArray)
	{
		arrayAverage += value;
	}
	cout << "Durchschnitt ist: " << arrayAverage / float(ARRAY_SIZE) << endl;

	//Differenz zweier benachbarter Zahlen im Array.
	cout << endl << "Differenz zweier benachbarter Zahlen im Array:" << endl;
	for (int i = 0; i < ARRAY_SIZE - 1; i++)
	{
		int differenz = iArray[i] - iArray[i + 1];
		cout << "Differenz von iArray[" << i << "] und iArray["<<i+1<<"] = " << differenz << endl;
	}

	return(0);
}