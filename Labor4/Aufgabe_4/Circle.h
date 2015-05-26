#pragma once
#include "Point.h"
#include "OneDimObject.h"

class Circle : public OneDimObject
{
	//FRIENDS
	//Circle in Stream ausgeben.
	friend std::ostream & operator<<(std::ostream & stream, const Circle & circle);

	//Circle von Stream einlesen.
	friend std::stringstream& operator>>(std::stringstream& stream, Circle& circle);

	public:
		//Standard Konstruktor.
		Circle();

		//Konstruktoren
		Circle(Point& point);
		Circle(std::string& str);
		Circle(Point& point, double radius);

		//Destruktor
		~Circle();

		//Gibt die Punkte und den Radius des Circles aus.
		void print(bool useEndl = true);

		//Konvertiert den Point in einen String.
		std::string toString();

		//Verschiebt die Koordianten des Cricles.
		void move(const double dx, const double dy);

	public:
		//Getter
		Point GetCentre()const{ return(m_Centre); }
		double GetRadius()const{ return(m_Radius); }

		//Setter
		void setCentre(const Point centre){ m_Centre = centre; }
		void setRadius(const double radius){ m_Radius = radius; }

	private:
		//Mittelpunkt des Kreises
		Point m_Centre;

		//Radius des Kreises
		double m_Radius;
};

