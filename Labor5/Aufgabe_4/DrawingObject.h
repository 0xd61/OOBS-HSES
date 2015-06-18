#pragma once
#include "ObjectCounter.h"
class DrawingObject :public ObjectCounter
{
public:
	DrawingObject();
	~DrawingObject();
	static unsigned int getNumber();

	virtual void print(bool = false) const = 0;
};

