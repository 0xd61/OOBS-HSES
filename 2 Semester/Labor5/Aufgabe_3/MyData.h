#pragma once

class MyData
{
	public:
		virtual ~MyData(){}

		virtual MyData *clone() const = 0;
		virtual void print(bool value = true) const = 0;

		virtual MyData& operator=(const MyData &data)
		{
			return (*this);
		}
};