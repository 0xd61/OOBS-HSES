#include "Point.h"
#include <iostream>

using namespace std;


Point::Point() : m_X(0), m_Y(0)
{
}

Point::Point(const double x, const double y) : m_X(x), m_Y(y)
{

}

Point::~Point()
{
}

void Point::move(const double dx, const double dy)
{
	m_X += dx;
	m_Y += dy;
}

void Point::print(bool useEndl)
{
	if (useEndl)
	{
		cout << "(" << m_X << ", " << m_Y << ")" << endl;
	}
	else
	{
		cout << "(" << m_X << ", " << m_Y << ")";
	}
}
