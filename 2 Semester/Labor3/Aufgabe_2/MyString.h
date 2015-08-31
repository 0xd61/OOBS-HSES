#pragma once
#include <ostream>



class MyString
{
	friend std::ostream& operator<<(std::ostream& stream, MyString& string);
	friend std::ostream& operator<<(std::ostream& stream, const MyString& string);

	public:
		MyString();
		MyString(char * strPtr);
		MyString(const MyString& object);
		MyString(MyString & Object);
		~MyString();
		void reserve(unsigned int c);
		MyString & append(MyString & str);
		MyString& append(const MyString& str);

		MyString & assign(MyString & str);
		MyString& assign(const MyString& str);

	public:

		const char* c_str();
		const char* c_str() const;

		int size();
		int size() const;

		int capacity();
		int capacity() const;


		void clear();

		bool empty();
		bool empty() const;

		char & at(int i);

	public:
		MyString operator+(MyString& string);
		MyString operator+(const MyString& string) const;

		bool operator==(const MyString& string);
		bool operator==(const MyString& string) const;

		char& operator[](const int index);

		MyString& operator=(MyString& string);
		MyString& operator=(const MyString& string);
		

	private:
		char * strPtr;
		unsigned int strSize, strCapacity;

};