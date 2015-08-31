#include "Fifo.h"
#include <iostream>


Fifo::Fifo(int maxSize)
{
	this->ptr = new char[maxSize];
	this->maxSize = maxSize;
	this->number = 0;
	this->rPos = 0;
	this->wPos = 0;

}

Fifo::~Fifo()
{
	if (ptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}
}

int Fifo::getWPos()
{
	return wPos;
}

int Fifo::getRPos()
{
	return rPos;
}

bool Fifo::isEmpty()
{
	if (number == 0)
		return true;
	else
		return false;
}

bool Fifo::isFull()
{
	if (number == maxSize)
		return true;
	else
		return false;
}

int Fifo::push(char c)
{
	if (isFull())
		return -1;
	if (wPos == maxSize)
		wPos = 0;
		
	ptr[wPos] = c;
	number++;
	return wPos++; //zuerst zurückgeben, dann inkrement
}

char Fifo::pop()
{
	if (isEmpty())
		return NULL;

	if (rPos == maxSize)
		rPos = 0;

	number--;
	return (ptr[rPos++]); //zuerst ArrayWert zurückgeben, dann inkrement
}