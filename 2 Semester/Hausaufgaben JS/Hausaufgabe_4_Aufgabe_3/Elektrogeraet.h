#pragma once
class Elektrogeraet
{
	public:
		Elektrogeraet();
		Elektrogeraet(const unsigned int watt_value);
		~Elektrogeraet();

		void print();

	public:
		void setWatt(const unsigned int watt_value);
		unsigned int getWatt() const;

	protected:
		unsigned int watt;
};

