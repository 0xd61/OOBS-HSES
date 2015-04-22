#pragma once
#include "MyString.h"
#include <ostream>

class Fahrzeug
{
	///<summary>Streaming Operator.</summary>
	friend std::ostream& operator<<(std::ostream& stream, Fahrzeug& fahrzeug);

	public:
		///<summary>Standard Konstruktor.</summary>
		Fahrzeug(char* kennzeichen);

		///<summary>Standard Dekonstruktor.</summary>
		~Fahrzeug();

		///<summary>Erhöht den Kilometerzähler.</summary>
		void fahren(double km);

		static int zaehler;

	private:
		///<summary>Kennzeichen.</summary>
		MyString kz;

		///<summary>Vehicle Identification Number.</summary>
		const int vin;

		///<summary>Gefahrene Kilometer.</summary>
		double km;
};

