#include <conio.h>
#include <iostream>
#include <fstream>
#include "Labyrinth.h"

using namespace std;

int max_own(int x, int y)
{
	return (x <= y) ? y : x;
}

// Hilfsfunktion min
int min_own(int x, int y)
{
	return (x <= y) ? x : y;
}

unsigned int Labyrinth::getZeilen()
{
	return(m_LabZeilen);
}

unsigned int Labyrinth::getSpalten()
{
	return(m_LabSpalten);
}

unsigned int Labyrinth::getAnzGeister()
{
	return(m_LabAnzGeister);
}

char Labyrinth::getZeichenAnPos(Position pos)
{
	return(m_Lab[pos.posx][pos.posx]);
}

bool Labyrinth::istMuenzeAnPos(Position pos)
{
	return(m_Lab[pos.posx][pos.posy] == MUENZE);
}

unsigned int Labyrinth::getMuenzen()
{
	return(m_Muenzen);
}

Labyrinth::Labyrinth() : m_LabAnzGeister(5), m_Muenzen(0) , m_LabZeilen(kZeilen) , m_LabSpalten(kSpalten)
{
	initialisieren();
}

Labyrinth::Labyrinth(unsigned int zeilen, unsigned int spalten, unsigned int anzahlGeister) :m_LabZeilen(zeilen), m_LabSpalten(spalten), m_LabAnzGeister(anzahlGeister), m_Muenzen(0)
{
	initialisieren();
}

void Labyrinth::initialisieren()
{
	for (int zeile = 0; zeile < kZeilen; zeile++)
	{
		for (int spalte = 0; spalte < kSpalten; spalte++)
		{
			m_Lab[zeile][spalte] = '#';
		}

		//Vorletzte und letzte Spalte befüllen.
		m_Lab[zeile][kSpalten] = '\n';
		m_Lab[zeile][kSpalten + 1] = '\0';

	}
}

void Labyrinth::drucken()
{
	// Console frei machen
	system("cls");

	// Labyrinth ausgeben
	/* HIER */
	for (int zeile = 0; zeile < kZeilen; zeile++)
	{
		for (int spalte = 0; spalte < kSpalten + 1; spalte++)
		{
			cout << m_Lab[zeile][spalte];
		}

	}
}

void Labyrinth::erzeugen()
{
	char c = 'x';
	int posx = kSpalten / 2;
	int posy = kZeilen / 2;

	m_Lab[posy][posx] = ICH;
	drucken();

	while (c != 'q')
	{
		drucken();
		cout << "Laufen mit Pfeiltasten. Beenden mit q." << endl;

		m_Lab[posy][posx] = WEG;
		c = _getch();

		switch (int(c))
		{
			// oben
		case 72: posy = max_own(1, posy - 1); break;

			// links
		case 75: posx = max_own(1, posx - 1); break;

			// rechts
		case 77: posx = min_own(kSpalten - 2, posx + 1); break;

			// unten
		case 80: posy = min_own(kZeilen - 2, posy + 1); break;

			// q = quit
		case 113: break;
		}

		m_Lab[posy][posx] = ICH;
	}
}

void Labyrinth::legeMuenzen()
{
	for (int zeile = 0; zeile < kZeilen; zeile++)
	{
		for (int spalte = 0; spalte < kSpalten; spalte++)
		{
			if (m_Lab[zeile][spalte] == ' ')
			{
				m_Lab[zeile][spalte] = MUENZE;
				m_Muenzen++;
			}
		}

	}
}

void Labyrinth::zeichneChar(char c, Position pos)
{
	m_Lab[pos.posx][pos.posx] = c;
}

void Labyrinth::zeichneChar(char c, Position posalt, Position posneu)
{
	m_Lab[posneu.posx][posneu.posy] = c;
	m_Lab[posalt.posx][posalt.posy] = ' ';

}

void Labyrinth::exportDatei(char *fileName)
{
	ofstream datei(fileName);
	if (!datei) 
	{
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) 
	{
		datei << m_Lab[i];
	}
	datei.close();
}

void Labyrinth::importDatei(char *fileName)
{
	ifstream datei(fileName);
	if (!datei) 
	{
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) 
	{
		datei.getline(m_Lab[i], kSpalten + 2);
		m_Lab[i][kSpalten] = '\n';
		m_Lab[i][kSpalten + 1] = '\0';
	}
	datei.close();
}