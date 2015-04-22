#include "Polygonline.h"
#include <iostream>
#include <sstream>

using namespace std;

//--------------------------------------------------------------------------------------
//Standart Konstruktor.
//--------------------------------------------------------------------------------------
Polygonline::Polygonline() : m_StartElement(nullptr), m_LastElement(nullptr)
{
}

//--------------------------------------------------------------------------------------
//Konstruktor.
//--------------------------------------------------------------------------------------
Polygonline::Polygonline(Point point)
{
	m_StartElement = new PlgElement(point);
	m_LastElement = m_StartElement;
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
void Polygonline::appendPolygonline(Polygonline& polygonline)
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

