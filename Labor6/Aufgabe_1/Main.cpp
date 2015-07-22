// main.cpp zur Demonstration der vorhersehbaren Fehler

#include <iostream>
#include "Polygonline.h"
using namespace std;

bool debugConstructor = false;

unsigned int ObjectCounter::maxID = 0;
unsigned int ObjectCounter::number = 0;

int main() {
	// Punkt erstellen und Infos ausgeben
	const Point p;
	cout << "maxId = " << ObjectCounter::getMaxId() << endl;
	cout << "ID von p = " << p.getId() << endl;

	try
	{
		// ID von p unerlaubt ändern
		*(((int*)(&p)) + 1) = ObjectCounter::getMaxId() + 10;
		p.check();
	}
	catch (DrawingObject::IdTooHigh &e)
	{
		cout << endl << "EXCEPTION: IdTooHigh " << e.getID() << endl;
	}
	
	// Punkt ausgeben
	cout << "ID von p = " << p.getId() << endl;
	p.print();
	// Polygonline erstellen und ausgeben
	Polygonline pl;
	pl.addPoint(Point(1, 1));
	pl.addPoint(Point(2, 2));
	pl.addPoint(Point(3, 3));
	pl.addPoint(Point(4, 4));
	pl.print();
	// Polygonline unerlaubt ändern
	PlgElement * first = (PlgElement *)(*((int*)(&pl) + 2));
	PlgElement * last = (PlgElement *)(*((int*)(&pl) + 3));
	last->setNext(first);
	// Polygonline ausgeben
	try
	{
		pl.print();

	}
	catch (Polygonline::LoopInLine& e)
	{
		cout << endl <<  "EXCEPTION: PlgElement wurde schon aufgerufen." << endl;
	}

	getchar();
	getchar();
	return 0;
}
