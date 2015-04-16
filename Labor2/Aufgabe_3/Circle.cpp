#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle() : m_Centre(), m_Radius(0)
{
}

Circle::Circle(Point& point) : m_Centre(point), m_Radius(0)
{
	
}

Circle::~Circle()
{
	
}

void Circle::move(const double dx, const double dy)
{
	m_Centre.move(dx, dy);
}

void Circle::print(bool useEndl)
{
	if (useEndl)
	{
		cout << "<(" << m_Centre.getX() << ", " << m_Centre.getY() << "), " << m_Radius << ">"  << endl;
	}
	else
	{
		cout << "<(" << m_Centre.getX() << ", " << m_Centre.getY() << "), " << m_Radius;
	}
}
