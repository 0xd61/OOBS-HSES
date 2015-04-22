#include "Fahrzeug.h"
#include <time.h>

//Gesamt Kilometerzähler setzen.
double Fahrzeug::summeKm = 0;

//--------------------------------------------------------------------------------------
//Standard Konstruktor.
//--------------------------------------------------------------------------------------
Fahrzeug::Fahrzeug(char* kennzeichen) : vin(reinterpret_cast<unsigned int>(this))
{
	//Kennzeichen speichern.
	kz = MyString(kennzeichen);
}

//--------------------------------------------------------------------------------------
//Standard Dekonstruktor.
//--------------------------------------------------------------------------------------
Fahrzeug::~Fahrzeug()
{
	//Gesamt kilometerstand verringern.
	summeKm -= this->km;
}

//--------------------------------------------------------------------------------------
//Erhöht den Kilometerzähler.
//--------------------------------------------------------------------------------------
void Fahrzeug::fahren(double km)
{
	this->km += km;
	summeKm += km;
}

double Fahrzeug::getSummeKm()
{
	return(summeKm);
}

//--------------------------------------------------------------------------------------
//Streaming Operator.
//--------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& stream, Fahrzeug& fahrzeug)
{
	stream << "Kz = " << fahrzeug.kz.c_str() << "   VIN = " << fahrzeug.vin << "   Km = " << fahrzeug.km;

	return(stream);
}
