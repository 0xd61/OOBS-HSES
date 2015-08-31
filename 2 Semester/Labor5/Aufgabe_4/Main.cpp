#include<iostream>
#include <string>
#include <regex>
#include <exception>

#include "Point.h"
#include "Rectangle.h"
#include "Polygonline.h"
#include "Circle.h"


using namespace std;

bool debugConstructor = true;
unsigned int ObjectCounter::maxID = 0;
unsigned int ObjectCounter::number = 0;

enum OBJECT_TYPE
{
	POINT,
	CIRCLE,
	POLYGONLINE,
	RECTANGLE,
	NO_TYPE,
};

OBJECT_TYPE IndicateObject(string objectAsString)
{
	//Regex für float zahlen.
	string regexStringFloat = "[0-9]+\.[0-9]*";

	//Beliebig viel whiteSpace.
	string whitespace = "[[:space:]]*";

	string regexStringPoint = "\\(" + whitespace + regexStringFloat + whitespace + "\," + whitespace + regexStringFloat + whitespace + "\\)";

	regex point(regexStringPoint);
	regex cirlce("\<" + whitespace + regexStringPoint + whitespace + "\," + whitespace + regexStringFloat +whitespace +"\>");
	regex polygonLine("\\|" + whitespace + "(" + regexStringPoint + whitespace + "\-" + whitespace + ")*" + regexStringPoint + whitespace + "\\|");
	regex rectangle("\\[" + whitespace + regexStringPoint + whitespace +"\," +whitespace +regexStringPoint +whitespace +"\\]");

	
	if (regex_match(objectAsString, point))
	{
		//cout << "Point gefunden" << endl;
		return(POINT);
	}
	else if (regex_match(objectAsString, cirlce))
	{
		//cout << "Circle gefunden" << endl;
		return(CIRCLE);
	}
	else if (regex_match(objectAsString, polygonLine))
	{
		//cout << "Polygonline gefunden" << endl;
		return(POLYGONLINE);
	}
	else if (regex_match(objectAsString, rectangle))
	{
		//cout << "Rectangle gefunden" << endl;
		return(RECTANGLE);
	}

	//cout << "Nichts gefunden" << endl;

	return(NO_TYPE);
}

int main()
{
	DrawingObject * objects[20];
	int anzahl = 0;
	cout << "Wieviele Objekte wollen Sie einlesen?" << endl;
	cout << "Anzahl: ";
	cin >> anzahl;
	fflush(stdin);

	string objectAsString[4];
	objectAsString[0] = "(9.0,9.0)";
	objectAsString[1] = "< (  9.0,  9.0)  ,   10.1   >";
	objectAsString[2] = "|(1.0,1.0) - (8.0,2.0) - (3.0,3.0) - (4.0,4.0)|";
	objectAsString[3] = "[  (9.0,9.0) ,(8.0, 8.0)]";
	
	// Objekte einlesen
	for (int i = 0; i<anzahl; i++)
	{
		// einzelnes Objekt einlesen
		//cin >> objectAsString;

		OBJECT_TYPE type = IndicateObject(objectAsString[i]);

		switch (type)
		{
			case POINT: objects[i] = new Point(objectAsString[i]);
				break;

			case CIRCLE: objects[i] = new Circle(objectAsString[i]);
				break;

			case POLYGONLINE: objects[i] = new Polygonline(objectAsString[i]);
				break;

			case RECTANGLE: objects[i] = new Rectangle(objectAsString[i]);
				break;

			case NO_TYPE: cout << "Kein richtiger Typ eingegeben" << endl;
				break;
		}

		
	}

	// Objekte ausgeben
	for (int i = 0; i<anzahl; i++)
	{
		
		objects[i]->print(true);
	}
	cout << "Anzahl der Objekte: " << objects[0]->getNumber() << endl;

	getchar();
	return 0;
}