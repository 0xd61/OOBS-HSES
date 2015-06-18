#include "Circle.h"
#include <iostream>
#include <sstream>
#include <Windows.h>

using namespace std;

//--------------------------------------------------------------------------------------
//Standard Konstruktor.
//--------------------------------------------------------------------------------------
Circle::Circle() : m_Centre(), m_Radius(0)
{
}

//--------------------------------------------------------------------------------------
//Konstruktor.
//--------------------------------------------------------------------------------------
Circle::Circle(Point& point) : m_Centre(point), m_Radius(0)
{
	
}

Circle::Circle(Point & point, double radius) : m_Centre(point), m_Radius(radius)
{
	
}

Circle::Circle(std::string& str)
{
	int beginPoint = str.find("(")+1;
	int endPoint = str.find(")");


	Point p = Point(str.substr(beginPoint,endPoint-beginPoint));

	int begin = str.find("<")+1;
	int end = str.find(">");

	string completeValues = str.substr(begin, end-begin);

	int radiusBegin = completeValues.rfind(",");

	string radius = completeValues.substr(radiusBegin);
	int commaPosition = radius.find(",");
	radius = radius.replace(commaPosition, 1, "");

	m_Centre = p;
	m_Radius = stod(radius);


	
}

//--------------------------------------------------------------------------------------
//Destruktor.
//--------------------------------------------------------------------------------------
Circle::~Circle()
{

}

//--------------------------------------------------------------------------------------
//Verschiebt die Koordianten des Cricles.
//--------------------------------------------------------------------------------------
void Circle::move(const double dx, const double dy)
{
	m_Centre.move(dx, dy);
}

MyVectorData * Circle::clone() const
{
	Circle *clone = new Circle;
	clone->m_Centre = m_Centre;
	clone->m_Radius = m_Radius;

	return(clone);
}

void Circle::print(bool value) const
{
	if (value)
	{
		cout << "<(" << m_Centre.getX() << ", " << m_Centre.getY() << "), " << m_Radius << ">" << endl;
	}
	else
	{
		cout << "<(" << m_Centre.getX() << ", " << m_Centre.getY() << "), " << m_Radius << ">";
	}
}



//--------------------------------------------------------------------------------------
//Konvertiert den Point in einen String.
//--------------------------------------------------------------------------------------
string Circle::toString()
{
	stringstream stream;
	stream << "<(" << m_Centre.getX() << ", " << m_Centre.getY() << "), " << m_Radius << ">";

	return(stream.str());
}

//FRIENDS
//--------------------------------------------------------------------------------------
//Circle von Stream einlesen.
//--------------------------------------------------------------------------------------
std::stringstream& operator>>(std::stringstream& stream, Circle& circle)
{
	string str = stream.str();

	circle = Circle(str);

	return(stream);
}

//--------------------------------------------------------------------------------------
//Circle in Stream ausgeben.
//--------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & stream, const Circle & circle)
{
	stream << "<(" << circle.GetCentre().getX() << ", " << circle.GetCentre().getY() << "), " << circle.GetRadius() << ">";
	return stream;
}