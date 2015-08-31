#include "MyString.h"
#include <memory>
#include <string>

MyString::MyString()
{
	m_StrPtr = new char[50];
	m_StrCapacity = 50;
	m_StrSize = 0;
}

MyString::MyString(char *cString)
{
	m_StrPtr = new char[50];
	m_StrCapacity = 50;
	m_StrSize = 0;

	m_StrSize = strlen(cString);
	memcpy(m_StrPtr, cString, m_StrSize);
	m_StrPtr[m_StrSize] = '\0';
}

MyString::~MyString()
{
	//TODO: Hier ist ein memoy fehler.
	if (m_StrPtr != nullptr)
	{
		delete[] m_StrPtr;
		m_StrPtr = nullptr;
	}
	
}

void MyString::reserve(unsigned int c)
{
	if (m_StrCapacity >= c)
	{
		return;
	}

	//TODO: vlt noch ersatz array einfügen um den inhalt zu speichern.

	delete m_StrPtr;
	m_StrPtr = new char[c];
	m_StrCapacity = c;
}

MyString& MyString::append(MyString& str)
{
	int oldSize = m_StrSize;
	reserve(m_StrSize + str.size());

	memcpy(m_StrPtr + oldSize, str.m_StrPtr, str.m_StrSize);
	m_StrSize = oldSize + str.m_StrSize;
	m_StrPtr[m_StrSize] = '\0';

	return(*this);
}

MyString& MyString::assign(MyString& str)
{
	memset(m_StrPtr, 0, m_StrCapacity);
	memcpy(m_StrPtr, str.m_StrPtr, str.m_StrSize);
	m_StrSize = str.m_StrSize; 

	return(*this);
}

MyString& MyString::operator+(MyString& str)
{
	return(append(str));
}

const char* MyString::c_str()
{
	return(m_StrPtr);
}

unsigned int MyString::size()
{
	return(m_StrSize);
}

unsigned int MyString::capacity()
{
	return(m_StrCapacity);
}

void MyString::clear()
{
	reserve(1);
	m_StrPtr[0] = '\0';
	m_StrSize = 0;
}

bool MyString::empty()
{
	if (m_StrSize == 0)
	{
		return(true);
	}

	return(false);
}

char& MyString::at(unsigned int i)
{
	if ((i-1) > m_StrSize)
	{
		return(m_StrPtr[0]);
	}

	return(m_StrPtr[i-1]);
}