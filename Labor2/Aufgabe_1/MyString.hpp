#pragma once

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
	char* c_str();
	int size();
	int capacity();
	void clear();
	bool empty();
	char & at(int i);

private:
	char * strPtr;
	unsigned int strSize, strCapacity;

};