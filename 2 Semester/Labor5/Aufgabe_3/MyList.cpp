#include "MyList.h"

MyListElement::MyListElement()
{
	m_Data = nullptr;
	m_Next = nullptr;
	m_Previous = nullptr;
}

MyListElement::~MyListElement()
{
	m_Data = nullptr;
	m_Next = nullptr;
	m_Previous = nullptr;
}

void MyListElement::SetNext(MyListElement *element)
{
	m_Next = element;
}

MyListElement *MyListElement::GetNext() const
{
	return(m_Next);
}

void MyListElement::SetPrevious(MyListElement *element)
{
	m_Previous = element;
}

MyListElement * MyListElement::GetPrevious() const
{
	return(m_Previous);
}

void MyListElement::SetData(MyData &data)
{
	m_Data = &data;
}

MyData *MyListElement::GetData() const
{
	return(m_Data);
}




//--------------------------------------------------------------------------------------
//MYLIST
//--------------------------------------------------------------------------------------



MyList::MyList()
{
	m_Front = nullptr;
	m_Current = nullptr;
	m_Back = nullptr;
	m_Size = 0;
}

MyList::MyList(const MyList &list)
{
	m_Front = nullptr;
	m_Current = nullptr;
	m_Back = nullptr;
	m_Size = 0;
	MyListElement *element = list.m_Front;

	for (int i = 0; i < list.m_Size; i++)
	{
		push_back(*element->GetData());
		element = element->GetNext();
	}
}

MyList::~MyList()
{
}

void MyList::push_back(const MyData &data)
{
	if (m_Size == 0)
	{
		m_Front = new MyListElement;
		m_Current = m_Front;
		m_Back = m_Front;

		MyData *clone = data.clone();
		m_Current->SetData(*clone);

		m_Size++;

		return;
	}

	
	MyData *clone = data.clone();
	MyListElement *element = new MyListElement;
	element->SetData(*clone);
	element->SetPrevious(m_Current);
	m_Current->SetNext(element);

	m_Current = element;
	m_Back = m_Current;

	m_Size++;


}

void MyList::print()
{
	MyListElement *element = m_Front;


	for (int i = 0; i < m_Size; i++)
	{
		element->GetData()->print();
		element = element->GetNext();
	}
}

void MyList::pop_back()
{
	if (m_Size == 0)
	{
		return;
	}

	MyListElement *temp = m_Back->GetPrevious();
	
	delete m_Back;
	m_Back = nullptr;

	m_Back = temp;

	m_Size--;
}

void MyList::clear()
{
	MyListElement *temp = m_Front;

	for (int i = 0; i < m_Size; i++)
	{
		
		MyListElement *next = m_Front->GetNext();
		
		delete temp;
		temp = nullptr;
	}

	m_Size = 0;
}

bool MyList::empty()
{
	if (m_Size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

int MyList::size() const
{
	return(m_Size);
}

MyData& MyList::front() const
{
	return(*m_Front->GetData());
}

MyData& MyList::back() const
{
	return(*m_Back->GetData());

}

MyList MyList::operator = (const MyList &list)
{
	MyList newList;

	clear();
	MyListElement *element = list.m_Front;

	for (int i = 0; i < list.m_Size; i++)
	{
		push_back(*element->GetData());
		element = element->GetNext();
	}

	return(*this);
}

MyList MyList::operator+(const MyList &list)
{
	MyList newList;
	MyListElement *element = m_Front;

	for (int i = 0; i < m_Size; i++)
	{
		newList.push_back(*element->GetData());
		element = element->GetNext();
	}

	element = list.m_Front;
	for (int i = 0; i < list.m_Size; i++)
	{
		newList.push_back(*element->GetData());
		element = element->GetNext();
	}


	return(newList);
}