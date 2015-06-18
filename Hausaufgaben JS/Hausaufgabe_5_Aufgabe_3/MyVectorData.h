#pragma once

class MyVectorData
{
	public:
		virtual ~MyVectorData(){}

		virtual MyVectorData *clone() const = 0;
		virtual void print(bool value = true) const = 0;

		virtual MyVectorData& operator=(const MyVectorData &data)
		{
			return (*this);
		}
};