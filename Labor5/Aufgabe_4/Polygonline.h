#pragma once
#include "Point.h"
#include "OneDimObject.h"

//Listen Element f�r eine einfach verkettete Liste.
class PlgElement
{
	public:
		//Standard Konstruktor.
		PlgElement();

		//Konstruktor.
		PlgElement(Point point);


		//Dekonstruktor.
		~PlgElement();

	public:
		//Gibt das n�chste Elemenet der Liste zur�ck.
		PlgElement *getNext() const;

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
class Polygonline : public OneDimObject
{
	public:
		//FRIENDS. (Operatoren)
		//Polygon in Stream ausgeben.
		friend std::ostream & operator<<(std::ostream & stream, const Polygonline & polygon);

		//Standard Konstruktor.
		Polygonline();

		//Konstruktor.
		Polygonline(Point point);

		Polygonline(std::string& str);

		//Dekonstruktor.
		~Polygonline();

		//Gibt alle Punkte des Polygonzugs aus.
		void print(bool value = false) const override;

		//Gibt die Informationen als string zur�ck.
		std::string toString();

		//Bewegt alle Punkte des Polygonzugs.
		void move(const double dx, const double dy);

		//F�gt einen Punkt zum Polygonzug hinzu.
		Polygonline& addPoint(Point point);

		//F�gt einen anderen Polygonzug diesem hinzu. Es wird eine Tiefe kopie des alten Polygonzugs angelegt.
		void appendPolygonline(const Polygonline& polygonline);

		//Operatoren.
		//
		Polygonline& operator+(const Point & point);
		Polygonline& operator+(const Polygonline & line);
	public:
		//Gibt das erste Element der Liste zur�ck.
		PlgElement *getStartElement() const;

		//Gibt das letzte Element der Liste zur�ck.
		PlgElement *getLastElement() const;

	private:
		//Erstes Element der Liste.
		PlgElement *m_StartElement;

		//Letztes Element der Liste.
		PlgElement *m_LastElement;
};

