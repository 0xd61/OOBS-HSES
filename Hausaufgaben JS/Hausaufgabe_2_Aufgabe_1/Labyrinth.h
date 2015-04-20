#pragma once
#include "Position.h"

const unsigned int kZeilen = 11;
const unsigned int kSpalten = 11;

//// Hilfsfunktion max
//int max(int x, int y) {
//	return (x <= y) ? y : x;
//}
//
//// Hilfsfunktion min
//int min(int x, int y) {
//	return (x <= y) ? x : y;
//}

// Zeichen, die im Labyrinth vorkommen können,
// NL = new line, EOS = end of string
enum Symbole {
	MAUER = '#', WEG = ' ', MUENZE = ':', NL = '\n',
	EOS = '\0', ICH = 'X', GEIST = 'G'
};

class Labyrinth
{
public:
	Labyrinth();
	Labyrinth(unsigned int zeilen, unsigned int spalten, unsigned int anzahlGeister);
	
	void initialisieren();
	void drucken();
	void erzeugen();
	void legeMuenzen();
	void zeichneChar(char c, Position pos);
	void zeichneChar(char c, Position posalt , Position posneu);

	void exportDatei(char *fileName);
	void importDatei(char *fileName);

	unsigned int getZeilen();
	unsigned int getSpalten();
	unsigned int getAnzGeister();
	unsigned int getMuenzen();
	char getZeichenAnPos(Position pos);
	bool istMuenzeAnPos(Position pos);

private:
	// Hilfsfunktion max
	int max(int x, int y) {
		return (x <= y) ? y : x;
	}

	// Hilfsfunktion min
	int min(int x, int y) {
		return (x <= y) ? x : y;
	}

private:
	
	//Größe des Labyrinth
	unsigned int m_LabZeilen;
	unsigned int m_LabSpalten;
	
	//Anzahl der Geister die im Labyrinth unterwegs sind.
	unsigned int m_LabAnzGeister;

	//Anzahl der Münzen im Lavyrinth.
	unsigned int m_Muenzen;

	char m_Lab[kZeilen][kSpalten+2];

};