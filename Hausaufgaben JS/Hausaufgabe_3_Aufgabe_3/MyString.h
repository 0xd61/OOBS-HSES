#pragma once
#include <ostream>

class MyString
{
	public:
		MyString();
		MyString(char * strPtr);
		MyString(MyString & Object);
		~MyString();
		void reserve(unsigned int c);
		MyString & append(MyString & str);
		MyString & assign(MyString & str);
		const char* c_str();
		int size();
		int capacity();
		void clear();
		bool empty();
		char & at(int i);

	public:
		MyString& operator+(MyString& string);
		bool operator==(const MyString& string);
		char& operator[](const int index);
		MyString& operator=(MyString& string);
		std::ostream& operator<<(std::ostream& stream);

	private:
		char * strPtr;
		unsigned int strSize, strCapacity;

};