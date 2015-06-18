#pragma once
#include <string>
#include <istream>
#include <ostream>
#include "DrawingObject.h"


class Point :public DrawingObject
{
	//FRIENDS
	//Punkt in Stream ausgeben.
	friend std::ostream & operator<<(std::ostream & stream, const Point& point);

	//Punkt von Stream einlesen.
	friend std::stringstream& operator>>(std::stringstream& stream, Point& point);

	//Addition von Punkt mit double Wert.
	friend Point & operator+(Point & point,double wert);

	//Addition von double Wert mit Punkt.
	friend Point & operator+(double wert, Point & point);

	public:
		//Standard Konstruktor.
		Point();

		//Konstruktoren.
		Point(const double x, const double y);
		Point(std::string& str);

		//KOPIERKONSTRUKTOR.
		Point(const Point &obj);

		//Destruktor.
		~Point();

		//Verschiebt die Koordianten des Punktes.
		void move(const double dx, const double dy);

		//Gibt die Punkte des Points aus.
		void print(bool useEndl = true) const override;


		//Konvertiert den Point in einen String.
		std::string toString();

		//OPERATOREN
		//Addition von Punkt mit Punkt.
		Point & operator+(const Point & point);

		//Präfix Inkrement von Punkt(++Point).
		Point & operator++();

		//Suffix Inkrement von Punkt (Point++).
		Point operator++(int);

		//Subtraktion von Punkt von Punkt.
		Point & operator-(const Point & point);

		//Negation von Punkt.
		Point & operator-();

	public:
		//Getter
		double getX()const{ return(m_X); }
		double getY()const{ return(m_Y); }

		//Setter
		void setX(const double x){ m_X = x; }
		void setY(const double y){ m_Y = y; }

	private:
		//X-Position
		double m_X;

		//Y-Position
		double m_Y;
};

