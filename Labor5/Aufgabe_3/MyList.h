#pragma once
#include "MyData.h"

class MyListElement
{
	public:
		MyListElement();
		~MyListElement();

		void SetNext(MyListElement *element);
		MyListElement *GetNext() const;

		void SetPrevious(MyListElement *element);
		MyListElement *GetPrevious() const;

		void SetData(MyData &data);
		MyData *GetData() const;

	private:
		MyListElement *m_Next;
		MyListElement *m_Previous;
		MyData *m_Data;

};

class MyList
{
	public:
		MyList();
		MyList(const MyList &list);
		~MyList();

		void push_back(const MyData &data);
		void pop_back();
		void clear();
		bool empty();
		int size() const;
		void print();

		MyData& front() const;
		MyData& back() const;

		MyList operator = (const MyList &list);
		MyList operator+(const MyList &);

	private:
		MyListElement *m_Front;
		MyListElement *m_Back;
		MyListElement *m_Current;
		int m_Size;
};

