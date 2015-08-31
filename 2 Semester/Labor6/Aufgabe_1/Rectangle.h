#pragma once
#include "Point.h"
#include "OneDimObject.h"
#include <string>

class Rectangle : public OneDimObject
{
	public:
		Rectangle();
		Rectangle(Point p1, Point p2);
		Rectangle(std::string& str);

		~Rectangle();

		void print(bool = false) const override;

	private:
		Point m_Point1;
		Point m_Point2;


};

