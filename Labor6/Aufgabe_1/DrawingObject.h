#pragma once
#include "ObjectCounter.h"
#include <exception>

class DrawingObject :public ObjectCounter
{
	public:
		class GraphException
		{
			public:
				GraphException(int id) : m_ObjectID(id){}

			protected:
				const int m_ObjectID;
		};

		class IdTooHigh : public GraphException
		{
			public:
				IdTooHigh(int id) : GraphException(id){}
				int getID() const { return(m_ObjectID); }
		};

	public:
		DrawingObject();
		~DrawingObject();
		static unsigned int getNumber();

		virtual void print(bool = false) const = 0;

		void check()const
		{
			if (m_ID > maxID)
			{
				throw IdTooHigh(m_ID);
			}
		}
};



