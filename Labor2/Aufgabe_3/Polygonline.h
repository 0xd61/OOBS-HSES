#pragma once
#include "Point.h"

//Listen Element für eine einfach verkettete Liste.
class PlgElement
{
	public:
		//Standart Konstruktor.
		PlgElement();

		//Konstruktor.
		PlgElement(Point point);

		//Dekonstruktor.
		~PlgElement();

	public:
		//Gibt das nächste Elemenet der Liste zurück.
		PlgElement *getNext();

		//Gibt den Point des aktuellen Elements zurück.
		Point& getPoint();

		//Setzt das nächste Element der Liste.
		void setNext(PlgElement *next);

		//Setzt den Point des aktuellen Listen Elements.
		void setPoint(Point point);

	private:

		//Position des Linienpunktes.
		Point m_Point;

		//Nächstes Element in der Liste.
		PlgElement *m_Next;
};

//Klasse für einen Polygonzug.
class Polygonline
{
	public:
		//Konstruktor.
		Polygonline();

		//Standart Konstruktor.
		Polygonline(Point point);

		//Dekonstruktor.
		~Polygonline();

		//Gibt alle Punkte des Polygonzugs aus.
		void print();

		//Bewegt alle Punkte des Polygonzugs.
		void move(const double dx, const double dy);

		//Fügt einen Punkt zum Polygonzug hinzu.
		Polygonline& addPoint(Point point);

		//Fügt einen anderen Polygonzug diesem hinzu. Es wird eine Tiefe kopie des alten Polygonzugs angelegt.
		void appendPolygonline(Polygonline& polygonline);

	public:
		//Gibt das erste Element der Liste zurück.
		PlgElement *getStartElement();

		//Gibt das letzte Element der Liste zurück.
		PlgElement *getLastElement();

	private:
		//Erstes Element der Liste.
		PlgElement *m_StartElement;

		//Letztes Element der Liste.
		PlgElement *m_LastElement;
};

