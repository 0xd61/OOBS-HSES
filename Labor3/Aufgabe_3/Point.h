#pragma once
#include <string>
#include <istream>



class Point
{
	public:
		Point();
		Point(const double x, const double y);
		Point(std::string& str);
		~Point();

		void move(const double dx, const double dy);
		void print(bool useEndl = true);

		std::string toString();

		friend std::stringstream& operator>>(std::stringstream& stream, Point& point);

	public:
		double getX()const{ return(m_X); }
		double getY()const{ return(m_Y); }

		void setX(const double x){ m_X = x; }
		void setY(const double y){ m_Y = y; }

	private:
		//X-Position
		double m_X;

		//Y-Position
		double m_Y;
};

