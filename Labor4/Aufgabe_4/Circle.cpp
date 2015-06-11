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
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Circle>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//--------------------------------------------------------------------------------------
//Konstruktor.
//--------------------------------------------------------------------------------------
Circle::Circle(Point& point) : m_Centre(point), m_Radius(0)
{
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Circle>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

Circle::Circle(Point & point, double radius) : m_Centre(point), m_Radius(radius)
{
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Circle>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
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


	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Circle>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//--------------------------------------------------------------------------------------
//Destruktor.
//--------------------------------------------------------------------------------------
Circle::~Circle()
{
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Dekonstruktor der Klasse <Circle>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//--------------------------------------------------------------------------------------
//Verschiebt die Koordianten des Cricles.
//--------------------------------------------------------------------------------------
void Circle::move(const double dx, const double dy)
{
	m_Centre.move(dx, dy);
}

//--------------------------------------------------------------------------------------
//Gibt die Punkte und den Radius des Circles aus.
//--------------------------------------------------------------------------------------
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