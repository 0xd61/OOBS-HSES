#define _CRT_SECURE_NO_WARNINGS
#include "MyVector.h"
#include "MyVectorData.h"
#include <cstring>
#include <iostream>

using namespace std;

MyVector::MyVector()
{
	//this->strPtr = new char;
	//this->strPtr[0] = '\0';
	//strSize = 0; //Ohne \0 Byte
	//strCapacity = 1;

	
	strPtr = new MyVectorData*[1];

	strCapacity = 1;
	strSize = 0;
}



MyVector::MyVector(char * strPtr)
{



}

MyVector::MyVector(const MyVector& object)
{
	strPtr = new MyVectorData*[object.size()];
	append(object);

	strCapacity = object.size();
	strSize = object.size();
}

MyVector::MyVector(MyVector & Object)
{
	strPtr = new MyVectorData*[Object.size()];
	append(Object);

	strCapacity = Object.size();
	strSize = Object.size();

}

MyVector::~MyVector()
{
	delete [] strPtr;
	strPtr = NULL;
}

//void MyVector::reserve(unsigned int c)
//{
//	if (c > strCapacity)
//	{
//		char * new_strPtr = new char[c];
//		strncpy(new_strPtr, strPtr, strCapacity);
//		delete [] strPtr;
//		strPtr = new_strPtr;
//		strSize = c-1; //Ohne \0 Byte
//		strCapacity = c;
//	}
//}
//
//MyVector & MyVector::append(MyVector & str)
//{
//	int oldSize = this->strSize; //Da die größe bei reserve verändert wird und der Index bei 0 anfängt
//	reserve(strCapacity + str.strSize); // keine Erhöhung, da Nullbyte schon in strCapacity enthalten
//	strncpy(&strPtr[oldSize], str.strPtr, str.strCapacity);
//	return *this;
//}
//
//MyVector & MyVector::append(const MyVector & str)
//{
//	int oldSize = this->strSize; //Da die größe bei reserve verändert wird und der Index bei 0 anfängt
//	reserve(strCapacity + str.strSize); // keine Erhöhung, da Nullbyte schon in strCapacity enthalten
//	strncpy(&strPtr[oldSize], str.strPtr, str.strCapacity);
//	return *this;
//}


void MyVector::push_back(const MyVectorData &d)
{
	if (strSize == strCapacity)
	{
		MyVectorData **temp = strPtr;
		strPtr = new MyVectorData*[strCapacity + 10];

		for (int i = 0; i < strSize; i++)
		{
			strPtr[i] = temp[i];
		}

		temp = nullptr;

		strCapacity += 10;

	}

	MyVectorData *data = d.clone();

	strPtr[strSize] = data;
	strSize++;
}

MyVector& MyVector::append(const MyVector& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		strPtr[strSize + i] = str.strPtr[i]->clone();
		
	}

	strSize += str.strSize;

	return(*this);
}

void MyVector::print()
{
	std::cout << "Vector wird ausgegeben:" << endl;

	for (int i = 0; i < strSize; i++)
	{
		strPtr[i]->print();
	}

	std::cout << "Vector ausgabe ende:" << endl << endl;

}

int MyVector::size()
{
	return strSize;
}

int MyVector::size() const
{
	return strSize;
}

int MyVector::capacity()
{
	return strCapacity;
}

int MyVector::capacity() const
{
	return strCapacity;
}

void MyVector::clear()
{
	for (int i = 0; i < strSize; i++)
	{
		delete strPtr[i];
		strPtr[i] = nullptr;
	}

	strSize = 0;
}

bool MyVector::empty()
{
	if (strSize == 0)
		return true;
	else
		return false;
}

bool MyVector::empty() const
{
	if (strPtr[0] == '\0')
		return true;
	else
		return false;
}

MyVectorData& MyVector::at(int i)
{
	if (i > strSize || i < 1)
		return *strPtr[0];
	else
		return *strPtr[i - 1];

}


bool MyVector::operator==(const MyVector& string)
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

bool MyVector::operator==(const MyVector& string) const
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



std::ostream& operator<<(std::ostream& stream, MyVector& string)
{
	//stream << string.c_str();
	return(stream);
}

std::ostream& operator<<(std::ostream& stream, const MyVector& string)
{
	//stream << string.c_str();
	return(stream);
}