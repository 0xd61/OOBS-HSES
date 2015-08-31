#pragma once
#include "Point.h"

class Circle
{
	public:
		Circle();
		Circle(Point& point);
		~Circle();

		void print(bool useEndl = true);
		void move(const double dx, const double dy);

	public:
		Point GetCentre()const{ return(m_Centre); }
		double GetRadius()const{ return(m_Radius); }

		void setCentre(const Point centre){ m_Centre = centre; }
		void setRadius(const double radius){ m_Radius = radius; }

	private:
		//Mittelpunkt des Kreises
		Point m_Centre;

		//Radius des Kreises
		double m_Radius;
};

