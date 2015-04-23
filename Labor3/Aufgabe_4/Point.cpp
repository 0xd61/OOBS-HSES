#include "Point.h"
#include <iostream>
#include <sstream>

using namespace std;


Point::Point() : m_X(0), m_Y(0)
{
}

Point::Point(const double x, const double y) : m_X(x), m_Y(y)
{

}

Point::Point(std::string& str)
{
	
	int begin = str.find("(")+1;
	int end = str.find(")");
	str = str.substr(begin, end - begin);


	int seperator = str.find(",");

	string x = str.substr(0, seperator);
	string y = str.substr(seperator+1);

	m_X = stod(x);
	m_Y = stod(y);
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
	stringstream stream;

	stream << "(" << m_X << ", " << m_Y << ")";

	if (useEndl)
	{
		stream << endl;
	}
	

	cout << stream.str();
}

string Point::toString()
{
	stringstream stream;
	stream << "(" << m_X << ", " << m_Y << ")";

	return(stream.str());
}

Point & Point::operator+(const Point & point)
{
	this->m_X += point.m_X;
	this->m_Y += point.m_Y;

	return *this;
}

Point & Point::operator++()
{
	++m_X; ++m_Y;
	return *this;
}

Point Point::operator++(int)
{
	Point p = *this;
	m_X++; m_Y++;
	return p;
}

Point & Point::operator-(const Point & point)
{
	this->m_X -= point.m_X;
	this->m_Y -= point.m_Y;

	return *this;
}

Point & Point::operator-()
{
	m_X = -m_X;
	m_Y = -m_Y;

	return *this;
}

//FRIENDS
std::stringstream& operator>>(std::stringstream& stream, Point& point)
{
	string str = stream.str();

	point = Point(str);

	return(stream);
}

std::ostream & operator<<(std::ostream & stream, const Point & point)
{
	stream << "(" << point.getX() << ", " << point.getY() << ")" << endl;
	return stream;
}

Point & operator+(Point & point,double wert)
{
	point.m_X += wert;
	point.m_Y += wert;

	return point;
}

Point & operator+(double wert, Point & point)
{
	point.m_X += wert;
	point.m_Y += wert;

	return point;
}