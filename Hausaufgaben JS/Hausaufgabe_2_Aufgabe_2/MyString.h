#pragma once

class MyString
{
	//friend class MyString;

public:
	MyString();
	MyString(char *cString);
	~MyString();

	void reserve(unsigned int c);
	MyString& append(MyString& str);
	MyString& assign(MyString& str);

	const char* c_str();
	unsigned int size();
	unsigned int capacity();
	void clear();
	bool empty();
	char& at(unsigned int i);

public:
	MyString& operator+(MyString& str);

private:
	char *m_StrPtr;
	unsigned int m_StrSize;
	unsigned int m_StrCapacity;
};