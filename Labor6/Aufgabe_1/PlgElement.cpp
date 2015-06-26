#include "Polygonline.h"

//--------------------------------------------------------------------------------------
//Standard Konstruktor.
//--------------------------------------------------------------------------------------
PlgElement::PlgElement() : m_Next(nullptr), m_Point()
{
}

//--------------------------------------------------------------------------------------
//Konstruktor.
//--------------------------------------------------------------------------------------
PlgElement::PlgElement(Point& point) : m_Next(nullptr), m_Point(point)
{
}

//--------------------------------------------------------------------------------------
//Dekonstruktor.
//--------------------------------------------------------------------------------------
PlgElement::~PlgElement()
{
	if (m_Next != nullptr)
	{
		delete m_Next;
		m_Next = nullptr;
	}
}

//--------------------------------------------------------------------------------------
//Gibt das n�chste Elemenet der Liste zur�ck.
//--------------------------------------------------------------------------------------
PlgElement *PlgElement::getNext() const
{
	return(m_Next);
}

//--------------------------------------------------------------------------------------
//Gibt den Point des aktuellen Elements zur�ck.
//--------------------------------------------------------------------------------------
Point& PlgElement::getPoint()
{
	return(m_Point);
}

//--------------------------------------------------------------------------------------
//Setzt das n�chste Element der Liste.
//--------------------------------------------------------------------------------------
void PlgElement::setNext(PlgElement *next)
{
	m_Next = next;
}

//--------------------------------------------------------------------------------------
//Setzt den Point des aktuellen Listen Elements.
//--------------------------------------------------------------------------------------
void PlgElement::setPoint(Point& point)
{
	m_Point = point;
}