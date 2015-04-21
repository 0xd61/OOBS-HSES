#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <cstring>

MyString::MyString()
{
	this->strPtr = new char;
	this->strPtr[0] = '\0';
	strSize = 0; //Ohne \0 Byte
	strCapacity = 1;
}



MyString::MyString(char * strPtr)
{
	strSize = strlen(strPtr);
	strCapacity = strlen(strPtr)+1;
	this->strPtr = new char[strCapacity];
	strncpy(this->strPtr, strPtr,strCapacity);


}

MyString::MyString(MyString & Object)
{
	this->strCapacity = Object.strCapacity;
	this->strSize = Object.strSize;
	this->strPtr = new char[this->strCapacity];
	strncpy(this->strPtr, Object.strPtr, strCapacity);

}

MyString::~MyString()
{
	delete [] strPtr;
	strPtr = NULL;
}

void MyString::reserve(unsigned int c)
{
	if (c > strCapacity)
	{
		char * new_strPtr = new char[c];
		strncpy(new_strPtr, strPtr, strCapacity);
		delete [] strPtr;
		strPtr = new_strPtr;
		strSize = c-1; //Ohne \0 Byte
		strCapacity = c;
	}
}

MyString & MyString::append(MyString & str)
{
	int oldSize = this->strSize; //Da die größe bei reserve verändert wird und der Index bei 0 anfängt
	reserve(strCapacity + str.strSize); // keine Erhöhung, da Nullbyte schon in strCapacity enthalten
	strncpy(&strPtr[oldSize], str.strPtr, str.strCapacity);
	return *this;
}

MyString & MyString::assign(MyString & str)
{
	reserve(strlen(str.strPtr) + 1);
	strncpy(strPtr, str.strPtr, str.strCapacity);
	return *this;
}

const char * MyString::c_str()
{
	return strPtr; //Dafür sorgen, dass keine Manipulation vorgenommen werden kann
}

int MyString::size()
{
	return strSize;
}

int MyString::capacity()
{
	return strCapacity;
}

void MyString::clear()
{
	reserve(1);
	strPtr[0] = '\0'; //NICHT einfach strPtr = '\0' zuweisen
}

bool MyString::empty()
{
	if (strPtr[0] == '\0')
		return true;
	else
		return false;
}

char & MyString::at(int i)
{
	if (i > strSize || i < 1)
		return strPtr[0];
	else
		return strPtr[i - 1];

}

MyString MyString::operator+(MyString& string)
{
	MyString tmp;
	tmp.assign(*this);
	tmp.append(string);
	return(tmp);
}

bool MyString::operator==(const MyString& string)
{
	int compareSize = (strSize>string.strSize) ? strSize : string.strSize;
	
	if (memcmp(strPtr, string.strPtr, compareSize) == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

char& MyString::operator[](const int index)
{
	if (index > strSize)
	{
		return(strPtr[0]);
	}

	return(strPtr[index]);
}

MyString& MyString::operator=(MyString& string)
{
	 return(assign(string));
}

std::ostream& operator<<(std::ostream& stream, MyString& string)
{
	stream << string.c_str();
	return(stream);
}