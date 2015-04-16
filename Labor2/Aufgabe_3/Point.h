#pragma once
class Point
{
	public:
		Point();
		Point(const double x, const double y);
		~Point();

		void move(const double dx, const double dy);
		void print(bool useEndl = true);

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

