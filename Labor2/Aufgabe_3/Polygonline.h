#pragma once
#include "Point.h"

class PlgElement
{
	public:
		~PlgElement();

	private:
		Point m_Point;
		PlgElement *m_Next;
};

class Polygonline
{
	public:
		Polygonline();
		~Polygonline();
};

