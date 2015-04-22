#include "Point.h"
#include <iostream>
#include <string>
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
	
	int begin = str.find("(");
	int end = str.find(")");

	if (begin >= 0 && end >= 0)
	{
		str = str.substr(begin, end - begin);
	}

	begin = str.find("(");
	end = str.find(")");

	if (begin >= 0)
	{
		str =  str.replace(begin, 1, "");
	}

	if (end >= 0)
	{
		str = str.replace(end-1, 1, "");
	}

	

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

std::stringstream& operator>>(std::stringstream& stream, Point& point)
{
	string str = stream.str();

	point = Point(str);

	return(stream);
}
