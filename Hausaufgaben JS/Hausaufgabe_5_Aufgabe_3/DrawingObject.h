#pragma once
#include "ObjectCounter.h"
#include "MyVectorData.h"
class DrawingObject :public ObjectCounter, public MyVectorData
{
public:
	DrawingObject();
	~DrawingObject();
	static unsigned int getNumber();

	virtual void print(bool = false) const = 0;
};

