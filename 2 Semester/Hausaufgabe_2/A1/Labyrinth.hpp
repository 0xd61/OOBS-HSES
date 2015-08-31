#pragma once

class Position;

// Zeichen, die im Labyrinth vorkommen können,
// NL = new line, EOS = end of string
enum Symbole
 {
	MAUER = '#', WEG = ' ', MUENZE = ':', NL = '\n',
	EOS = '\0', ICH = 'X', GEIST = 'G'
};

// Größe des Labyrinths
const int kZeilen = 11;
const int kSpalten = 11;


//Klasse Labyrinth
class Labyrinth
{
public:
	//Konstruktor
	Labyrinth();
	// Labyrinth mit # füllen
	void initialisieren();
	// Labyrinth auf dem Bildschirm ausgeben
	void drucken();
	// Durch Herumlaufen werden Wege im Labyrinth erzeugt
	// ASCII-Wert der Tasten: oben 72, links 75, rechts 77, unten 80
	void erzeugen();
	int max(int x, int y);
	int min(int x, int y);
	int getZeilen();
	int getSpalten();
	int getAnzGeister();
	int getMuenzen();
	void legeMuenzen();
	void zeichneChar(char c, Position pos);
	void zeichneChar(char c, Position posalt, Position posneu);
	char getZeichenAnPos(Position pos);
	bool istMuenzeAnPos(Position pos);
	void exportDatei(char * dateiname);
	void importDatei(char * dateiname);


private:
	int labZeilen;
	int labSpalten;
	int	labAnzGeister;
	int muenzen;
	char lab[kZeilen][kSpalten + 2];

};