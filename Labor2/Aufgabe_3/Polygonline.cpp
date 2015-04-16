#include "Polygonline.h"

PlgElement::~PlgElement()
{
	if (m_Next)
	{
		delete m_Next;
		m_Next = nullptr;
	}
}

Polygonline::Polygonline()
{
}


Polygonline::~Polygonline()
{
}
