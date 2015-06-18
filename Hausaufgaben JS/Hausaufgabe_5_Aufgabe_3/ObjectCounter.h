#pragma once
class ObjectCounter
{
	public:
		ObjectCounter();
		~ObjectCounter();

	public:
		unsigned int getId();
		unsigned int getMaxId();
		static unsigned int getNumber();

	protected:
		unsigned int m_ID;
		static unsigned int maxID;
		static unsigned int number;


};

