#include "Fahrzeug.h"
#include <time.h>

//--------------------------------------------------------------------------------------
//Standard Konstruktor.
//--------------------------------------------------------------------------------------
Fahrzeug::Fahrzeug(char* kennzeichen)
{
	//Kennzeichen speichern.
	kz = MyString(kennzeichen);

	//Eindeutige ID vergeben. Nimmt die Adresse des objekts als ID.
	vin = reinterpret_cast<unsigned int>(this);
}

//--------------------------------------------------------------------------------------
//Standard Dekonstruktor.
//--------------------------------------------------------------------------------------
Fahrzeug::~Fahrzeug()
{
}

//--------------------------------------------------------------------------------------
//Erhöht den Kilometerzähler.
//--------------------------------------------------------------------------------------
void Fahrzeug::fahren(double km)
{
	this->km += km;
}

//--------------------------------------------------------------------------------------
//Streaming Operator.
//--------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& stream, Fahrzeug& fahrzeug)
{
	stream << "Kz = " << fahrzeug.kz.c_str() << "   VIN = " << fahrzeug.vin << "   Km = " << fahrzeug.km;

	return(stream);
}
