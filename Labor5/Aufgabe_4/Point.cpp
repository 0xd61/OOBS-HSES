#include "Point.h"
#include <iostream>
#include <sstream>
#include <Windows.h>

using namespace std;

//--------------------------------------------------------------------------------------
//Standard Konstruktor.
//--------------------------------------------------------------------------------------
Point::Point() : m_X(0), m_Y(0)
{
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Konstruktor der Klasse <Point>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	}
}

//--------------------------------------------------------------------------------------
//Konstruktor.
//--------------------------------------------------------------------------------------
Point::Point(const double x, const double y) : m_X(x), m_Y(y)
{
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); 
		cout << "Konstruktor der Klasse <Point>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
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

//--------------------------------------------------------------------------------------
//Kopierkonstruktor.
//--------------------------------------------------------------------------------------
Point::Point(const Point &obj)
{
	*this = obj;

	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "Kopierkonstruktor der Klasse <Point>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//--------------------------------------------------------------------------------------
//Destruktor.
//--------------------------------------------------------------------------------------
Point::~Point()
{
	extern bool debugConstructor;

	if (debugConstructor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Dekonstruktor der Klasse <Point>, Objekt: <" << m_ID << ">" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//--------------------------------------------------------------------------------------
//Verschiebt die Koordinaten des Punktes.
//--------------------------------------------------------------------------------------
void Point::move(const double dx, const double dy)
{
	m_X += dx;
	m_Y += dy;
}

//--------------------------------------------------------------------------------------
//Gibt den Punkt aus.
//--------------------------------------------------------------------------------------
void Point::print(bool useEndl) const
{
	stringstream stream;

	stream << "(" << m_X << ", " << m_Y << ")";

	if (useEndl)
	{
		stream << endl;
	}
	

	cout << stream.str();
}

//--------------------------------------------------------------------------------------
//Konvertiert den Point zu einem String.
//--------------------------------------------------------------------------------------
string Point::toString()
{
	stringstream stream;
	stream << "(" << m_X << ", " << m_Y << ")";

	return(stream.str());
}

//OPERATOREN
//--------------------------------------------------------------------------------------
//Addition von Punkt mit Punkt.
//--------------------------------------------------------------------------------------
Point & Point::operator+(const Point & point)
{
	this->m_X += point.m_X;
	this->m_Y += point.m_Y;

	return *this;
}

//--------------------------------------------------------------------------------------
//Präfix Inkrement von Punkt (++Point).
//--------------------------------------------------------------------------------------
Point & Point::operator++()
{
	++m_X; ++m_Y;
	return *this;
}

//--------------------------------------------------------------------------------------
//Suffix Inkrement von Punkt (Point++).
//--------------------------------------------------------------------------------------
Point Point::operator++(int)
{
	Point p = *this;
	m_X++; m_Y++;
	return p;
}

//--------------------------------------------------------------------------------------
//Subtraktion von Punkt von Punkt.
//--------------------------------------------------------------------------------------
Point & Point::operator-(const Point & point)
{
	this->m_X -= point.m_X;
	this->m_Y -= point.m_Y;

	return *this;
}

//--------------------------------------------------------------------------------------
//Negation von Punkt.
//--------------------------------------------------------------------------------------
Point & Point::operator-()
{
	m_X = -m_X;
	m_Y = -m_Y;

	return *this;
}

//FRIENDS
//--------------------------------------------------------------------------------------
//Punkt von Stream einlesen.
//--------------------------------------------------------------------------------------
std::stringstream& operator>>(std::stringstream& stream, Point& point)
{
	string str = stream.str();

	point = Point(str);

	return(stream);
}

//--------------------------------------------------------------------------------------
//Punkt in Stream ausgeben.
//--------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & stream, const Point & point)
{
	stream << "(" << point.getX() << ", " << point.getY() << ")" << endl;
	return stream;
}

//--------------------------------------------------------------------------------------
//Addition von Punkt mit double Wert.
//--------------------------------------------------------------------------------------
Point & operator+(Point & point,double wert)
{
	point.m_X += wert;
	point.m_Y += wert;

	return point;
}

//--------------------------------------------------------------------------------------
//Addition von double Wert mit Punkt.
//--------------------------------------------------------------------------------------
Point & operator+(double wert, Point & point)
{
	point.m_X += wert;
	point.m_Y += wert;

	return point;
}