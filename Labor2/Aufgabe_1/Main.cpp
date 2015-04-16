#include "PacMan.h"
#include "Labyrinth.hpp"
#include "Spieler.h"

const bool kErzeugen = false;

int main() 
{
	Labyrinth lab;
	if (kErzeugen) 
	{
		lab.erzeugen();
		lab.exportDatei("lab.txt");
	}
	else 
	{
		lab.importDatei("lab.txt");
		lab.legeMuenzen();
		Spieler s("Demo");
		Spieler g[kAnzGeister] = { Spieler("Geist 1"),
			Spieler("Geist 2"),
			Spieler("Geist 3") };
		PacMan pm(lab, s, g, kAnzGeister);
		pm.spielen();
	}
	return 0;
}
