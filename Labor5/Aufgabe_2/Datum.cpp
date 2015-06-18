#include "Datum.hpp"

// Standardkonstruktor
Datum::Datum(int tag, int monat, int jahr) :tag(tag), monat(monat), jahr(jahr)
{}
// Konvertierkonstruktor für String
Datum::Datum(const string & date)
{
	tag = stoi(date.substr(0, 2));
	monat = stoi(date.substr(3, 2));
	jahr = stoi(date.substr(6, 4));
}
// Konvertierkonstruktor für C-String
Datum::Datum(const char * date)
{
	string tmp(date);

	tag = stoi(tmp.substr(0, 2));
	monat = stoi(tmp.substr(3, 2));
	jahr = stoi(tmp.substr(6, 4));
}
// Operator + addiert eine Anzahl von Tagen zum Datum hinzu
Datum Datum::operator+(int tage)
{
	tag += tage;
	if (tag > 30)
	{
		tag -= 30;
		monat++;
	}
	return *this;
}
// Ausgabeoperator <<, Ausgabe in dem Format tt.mm.jjjj
ostream & operator<<(ostream & stream, const Datum & date)
{
	stream << date.tag << "." << date.monat << "." << date.jahr;
	return stream;
}