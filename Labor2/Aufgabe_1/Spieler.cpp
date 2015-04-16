#include "Spieler.h"
#include <stdlib.h>

Spieler::Spieler()
{
	m_Pos = Position();
	m_Pos.r = Richtung::OBEN;

}

Spieler::Spieler(MyString& name)
{
	m_Name = name;
	m_Pos = Position();
	m_Pos.r = Richtung::OBEN;


}

Spieler::Spieler(char* name)
{
	m_Name = name;

	m_Pos = Position();
	m_Pos.r = Richtung::OBEN;

}

Position Spieler::getPos()
{
	return(m_Pos);
}

void Spieler::setPos(Position& position)
{
	m_Pos = position;
}

void Spieler::setRichtung(Richtung richtung)
{
	m_Pos.r = richtung;
}

unsigned int Spieler::getMuenzen()
{
	return(m_Muenzen);
}

void Spieler::plusMuenze()
{
	m_Muenzen++;
}

Spieler& Spieler::schritt(Labyrinth& lab)
{
	m_Pos.schritt(lab);
	return(*this);
}

void Spieler::orientieren(Labyrinth& lab)
{
	Position postmp = m_Pos;
	int rint = rand() % 4;
	postmp.r = Richtung(rint);

	while ((lab.getZeichenAnPos(postmp)) == MAUER)
	{
		rint = rand() % 4;
		postmp.r = Richtung(rint);
	}

	m_Pos.r = Richtung(rint);
}
