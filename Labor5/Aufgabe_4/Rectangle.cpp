#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(Point p1, Point p2)
{
	if (p1.getX() == p2.getX() && p1.getY() == p2.getY())
	{
		m_Point1 = Point(0, 0);
		m_Point2 = Point(1, 1);
	}
	else
	{
		m_Point1 = p1;
		m_Point2 = p2;
	}


}

Rectangle::Rectangle(std::string& str)
{
	int beginPoint1 = str.find("(");
	int endPoint1 = str.find(")")+1;
	std::string p1 = str.substr(beginPoint1, endPoint1 - beginPoint1);

	int beginPoint2 = str.find("(", endPoint1);
	int endPoint2 = str.find(")", endPoint1 +1)+1;
	std::string p2 = str.substr(beginPoint2, endPoint2 - beginPoint2);

	Point point1(p1);
	Point point2(p2);

	if (point1.getX() == point2.getX() && point1.getY() == point2.getY())
	{
		m_Point1 = Point(0, 0);
		m_Point2 = Point(1, 1);
	}
	else
	{
		m_Point1 = p1;
		m_Point2 = p2;
	}
}

Rectangle::~Rectangle()
{
}

void Rectangle::print(bool value) const 
{
	cout << "[(" << m_Point1.getX() << "," << m_Point1.getY() << ", ("
		<< m_Point2.getX() << "," << m_Point2.getY() << ")]" << endl;
}
