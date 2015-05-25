#include "Person.hpp"
#include <iostream>

// Standardkonstruktor
Person::Person(string name, int dauer) :name(name), ausleihdauer(dauer)
{}
// den Namen zurückliefern
string Person::getName() const
{
	return name;
}
// die Ausliehdauer zurückliefern
int Person::getAusleihdauer() const
{
	return ausleihdauer;
}
// die Person auf der Konsole ausgeben
void Person::print() const
{
	cout << name;
}