#pragma once
#include <string>

using namespace std;

class Haushaltsgeraet
{
	public:
		Haushaltsgeraet();
		Haushaltsgeraet(const string name_value, const double gewicht_value);
		~Haushaltsgeraet();

		void print();

	public:
		void setGewicht(const double gewicht_value);
		double getGewicht() const;

		string getName() const;


	protected:
		const string name;
		double gewicht;
};

