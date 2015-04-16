#pragma once

#include "MyString.hpp"
#include "Labyrinth.hpp"
#include "Position.h"

class Spieler
{
	public:
		Spieler();
		Spieler(MyString name);
		Spieler(char* name);

	public:
		Position getPos();
		void setPos(Position& position);
		void setRichtung(Richtung richtung);
		unsigned int getMuenzen();
		void plusMuenze();
		Spieler& schritt(Labyrinth& lab);
		void orientieren(Labyrinth& lab);

	private:
		MyString m_Name;
		Position m_Pos;
		unsigned int m_Muenzen;
};