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
	delete[] ptr;
	ptr = NULL;
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
	wPos++;
	number++;
	return (wPos-1);
}

char Fifo::pop()
{
	if (isEmpty())
		return NULL;

	if (rPos == maxSize)
		rPos = 0;

	number--;
	rPos++;
	return (ptr[rPos-1]); //-1, weil davor erhöht
}