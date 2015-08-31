#pragma once
#include "ObjectCounter.h"
#include "MyData.h"

class DrawingObject :public ObjectCounter, public MyData
{
public:
	DrawingObject();
	~DrawingObject();
	static unsigned int getNumber();

	virtual void print(bool = false) const = 0;
};

