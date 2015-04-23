#pragma once
#include <string>
#include <istream>
#include <ostream>


class Point
{
	friend std::ostream & operator<<(std::ostream & stream, const Point& point);
	friend std::stringstream& operator>>(std::stringstream& stream, Point& point);
	friend Point & operator+(Point & point,double wert);
	friend Point & operator+(double wert, Point & point);

	public:
		Point();
		Point(const double x, const double y);
		Point(std::string& str);
		~Point();

		void move(const double dx, const double dy);
		void print(bool useEndl = true);

		std::string toString();

		Point & operator+(const Point & point);
		Point & operator++();
		Point operator++(int);
		Point & operator-(const Point & point);
		Point & operator-();

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

