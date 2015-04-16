#include "Polygonline.h"
#include <iostream>

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
//F�gt einen Punkt zum Polygonzug hinzu.
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
//F�gt einen anderen Polygonzug diesem hinzu. Es wird eine Tiefe kopie des alten Polygonzugs angelegt.
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
//Gibt das erste Element der Liste zur�ck.
//--------------------------------------------------------------------------------------
PlgElement * Polygonline::getStartElement()
{
	return(m_StartElement);
}

//--------------------------------------------------------------------------------------
//Gibt das letzte Element der Liste zur�ck.
//--------------------------------------------------------------------------------------
PlgElement* Polygonline::getLastElement()
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

		//Nur einen Bindestrich schreiben wenn es auch ein n�chstes Element gibt.
		if (iterator->getNext() != nullptr)
		{
			cout << " - ";
		}

		iterator = iterator->getNext();

		
	}

	cout << "|" << endl;
}
