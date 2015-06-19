#include "Polygonline.h"
#include <iostream>
#include <sstream>
#include <Windows.h>

using namespace std;

//--------------------------------------------------------------------------------------
//Standart Konstruktor.
//--------------------------------------------------------------------------------------
Polygonline::Polygonline() : m_StartElement(nullptr), m_LastElement(nullptr)
{
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Polygonline>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//--------------------------------------------------------------------------------------
//Konstruktor.
//--------------------------------------------------------------------------------------
Polygonline::Polygonline(Point& point)
{
	m_StartElement = new PlgElement(point);
	m_LastElement = m_StartElement;

	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Polygonline>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

Polygonline::Polygonline(std::string& str)
{
	unsigned int numberOfPoints = 0;
	int pos = 0;

	//Anzahl an Punkten finden.
	while (pos != -1)
	{
		pos = str.find("-",pos+1);
		numberOfPoints++;
	}


	int pointBegin = 0;
	int pointEnd = 0;

	for (int i = 0; i < numberOfPoints; i++)
	{
		pointBegin = str.find("(",pointBegin+1)+1;
		pointEnd = str.find(")",pointEnd+1);

		string tmp = str.substr(pointBegin, pointEnd-pointBegin);

		addPoint(Point(tmp));
		
	}


	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Polygonline>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	
}



//--------------------------------------------------------------------------------------
//Dekonstruktor.
//--------------------------------------------------------------------------------------
Polygonline::~Polygonline()
{
	if (m_StartElement)
	{
		delete m_StartElement;
		m_StartElement = nullptr;
	}

	if (m_LastElement)
	{
		m_LastElement = nullptr;
	}

	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "´Dekonstruktor der Klasse <Polygonline>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//--------------------------------------------------------------------------------------
//Fügt einen Punkt zum Polygonzug hinzu.
//--------------------------------------------------------------------------------------
Polygonline& Polygonline::addPoint(Point point)
{
	if (m_StartElement == nullptr)
	{
		m_StartElement = new PlgElement(point);
		m_LastElement = m_StartElement;

	}
	else
	{
		m_LastElement->setNext(new PlgElement(point));
		m_LastElement = m_LastElement->getNext();
	}

	return(*this);
}

//--------------------------------------------------------------------------------------
//Fügt einen anderen Polygonzug diesem hinzu. Es wird eine Tiefe kopie des alten Polygonzugs angelegt.
//--------------------------------------------------------------------------------------
void Polygonline::appendPolygonline(const Polygonline& polygonline)
{
	PlgElement *iterator = polygonline.getStartElement();

	while (iterator)
	{
		//Tiefe Kopie anlegen.
		addPoint(iterator->getPoint());
		iterator = iterator->getNext();
	}

}

//--------------------------------------------------------------------------------------
//Gibt das erste Element der Liste zurück.
//--------------------------------------------------------------------------------------
PlgElement * Polygonline::getStartElement() const
{
	return(m_StartElement);
}

//--------------------------------------------------------------------------------------
//Gibt das letzte Element der Liste zurück.
//--------------------------------------------------------------------------------------
PlgElement* Polygonline::getLastElement() const
{
	return(m_LastElement);
}

//--------------------------------------------------------------------------------------
//Bewegt alle Punkte des Polygonzugs.
//--------------------------------------------------------------------------------------
void Polygonline::move(const double dx, const double dy)
{
	PlgElement *iterator = m_StartElement;

	while (iterator)
	{
		iterator->getPoint().move(dx, dy);
		iterator = iterator->getNext();
	}
}

//--------------------------------------------------------------------------------------
//Gibt alle Punkte des Polygonzugs aus.
//--------------------------------------------------------------------------------------
void Polygonline::print()
{
	PlgElement *iterator = m_StartElement;
	cout << "|";

	while (iterator)
	{
		iterator->getPoint().print(false);

		//Nur einen Bindestrich schreiben wenn es auch ein nächstes Element gibt.
		if (iterator->getNext() != nullptr)
		{
			cout << " - ";
		}

		iterator = iterator->getNext();

		
	}

	cout << "|" << endl;
}
//--------------------------------------------------------------------------------------
//Konvertiert die Poygonlinie in einen String.
//--------------------------------------------------------------------------------------
string Polygonline::toString()
{
	stringstream stream;

	PlgElement *iterator = m_StartElement;
	stream << "|";

	while (iterator)
	{
		 stream <<  iterator->getPoint().toString();

		//Nur einen Bindestrich schreiben wenn es auch ein nächstes Element gibt.
		if (iterator->getNext() != nullptr)
		{
			stream << " - ";
		}

		iterator = iterator->getNext();


	}

	stream << "|";

	return(stream.str());
}

//--------------------------------------------------------------------------------------
//Bei Polygon + Point einen Punkt hinzufuegen.
//--------------------------------------------------------------------------------------
Polygonline& Polygonline::operator+(const Point & point)
{
	this->addPoint(point);
	return *this;
}

//--------------------------------------------------------------------------------------
//Bei Polygon + Polygon die Linien zusammenfuegen.
//--------------------------------------------------------------------------------------
Polygonline& Polygonline::operator+(const Polygonline & line)
{
	this->appendPolygonline(line);

	return *this;
}

//FRIENDS
//--------------------------------------------------------------------------------------
//Die Polygonlinie als stream zurueckgeben.
//--------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & stream, const Polygonline & polygon)
{
	PlgElement *iterator = polygon.getStartElement();
	stream << "|";

	while (iterator)
	{
		stream << iterator->getPoint().toString();

		//Nur einen Bindestrich schreiben wenn es auch ein nächstes Element gibt.
		if (iterator->getNext() != nullptr)
		{
			stream << " - ";
		}

		iterator = iterator->getNext();


	}

	stream << "|";
	return stream;
}