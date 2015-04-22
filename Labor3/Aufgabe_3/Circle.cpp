#include "Circle.h"
#include <iostream>
#include <sstream>

using namespace std;

Circle::Circle() : m_Centre(), m_Radius(0)
{
}

Circle::Circle(Point& point) : m_Centre(point), m_Radius(0)
{
	
}

Circle::Circle(std::string& str)
{
	int beginPoint = str.find("(");
	int endPoint = str.find(")");


	Point p = Point(str.substr(beginPoint,endPoint));

	int begin = str.find("<");
	int end = str.find(">");

	string completeValues = str.substr(begin+1, end-1);

	int radiusBegin = completeValues.rfind(",");

	string radius = completeValues.substr(radiusBegin);
	int commaPosition = radius.find(",");
	radius = radius.replace(commaPosition, 1, "");

	m_Centre = p;
	m_Radius = stod(radius);
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

string Circle::toString()
{
	stringstream stream;
	stream << "<(" << m_Centre.getX() << ", " << m_Centre.getY() << "), " << m_Radius << ">";

	return(stream.str());
}

std::stringstream& operator>>(std::stringstream& stream, Circle& circle)
{
	string str = stream.str();

	circle = Circle(str);

	return(stream);
}