#include "ObjectCounter.h"

unsigned int ObjectCounter::maxID = 0;
unsigned int ObjectCounter::number = 0;

ObjectCounter::ObjectCounter() : m_ID(maxID++) 
{
	number++;
}


ObjectCounter::~ObjectCounter()
{
	maxID--;
	number--;
}


unsigned int ObjectCounter::getId()
{
	return(m_ID);
}

unsigned int ObjectCounter::getMaxId()
{
	return(maxID);
}

unsigned int ObjectCounter::getNumber()
{
	return(number);
}