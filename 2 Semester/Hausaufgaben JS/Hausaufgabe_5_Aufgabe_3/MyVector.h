#pragma once
#include <ostream>

class MyVectorData;

class MyVector
{
	friend std::ostream& operator<<(std::ostream& stream, MyVector& string);
	friend std::ostream& operator<<(std::ostream& stream, const MyVector& string);

	public:
		MyVector();
		MyVector(char * strPtr);
		MyVector(const MyVector& object);
		MyVector(MyVector & Object);
		~MyVector();

		MyVector& append(const MyVector& str);

		void push_back(const MyVectorData &d);
		void print();

	public:

		int size();
		int size() const;

		int capacity();
		int capacity() const;


		void clear();

		bool empty();
		bool empty() const;

		MyVectorData& at(int i);

	public:
		bool operator==(const MyVector& string);
		bool operator==(const MyVector& string) const;

private:
		MyVectorData **strPtr;
		unsigned int strSize, strCapacity;

};