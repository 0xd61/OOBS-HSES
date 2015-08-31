#pragma once

class MyString
{
public:
	MyString();
	MyString(char * strPtr);
	MyString(MyString & Object);
	~MyString();
	MyString & append(MyString & str);
	MyString & assign(MyString & str);
	char* c_str();
	int size();
	int capacity();
	void clear();
	bool empty();
	char & at(int i);

private:
	void reserve(unsigned int c);


private:
	char * strPtr;
	unsigned int strSize, strCapacity;

};