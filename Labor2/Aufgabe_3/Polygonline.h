#pragma once
#include "Point.h"

//Listen Element f�r eine einfach verkettete Liste.
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
		//Gibt das n�chste Elemenet der Liste zur�ck.
		PlgElement *getNext();

		//Gibt den Point des aktuellen Elements zur�ck.
		Point& getPoint();

		//Setzt das n�chste Element der Liste.
		void setNext(PlgElement *next);

		//Setzt den Point des aktuellen Listen Elements.
		void setPoint(Point point);

	private:

		//Position des Linienpunktes.
		Point m_Point;

		//N�chstes Element in der Liste.
		PlgElement *m_Next;
};

//Klasse f�r einen Polygonzug.
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

		//F�gt einen Punkt zum Polygonzug hinzu.
		Polygonline& addPoint(Point point);

		//F�gt einen anderen Polygonzug diesem hinzu. Es wird eine Tiefe kopie des alten Polygonzugs angelegt.
		void appendPolygonline(Polygonline& polygonline);

	public:
		//Gibt das erste Element der Liste zur�ck.
		PlgElement *getStartElement();

		//Gibt das letzte Element der Liste zur�ck.
		PlgElement *getLastElement();

	private:
		//Erstes Element der Liste.
		PlgElement *m_StartElement;

		//Letztes Element der Liste.
		PlgElement *m_LastElement;
};

