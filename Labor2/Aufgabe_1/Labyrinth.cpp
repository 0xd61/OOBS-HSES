//Labyrinth.cpp
#include "Labyrinth.hpp"
#include "Position.h"
#include <iostream>
#include <fstream>
#include <conio.h> // für _getch()
// Achtung: _getch() ist nicht im Standard und 
//          daher abhängig vom Compiler

using namespace std;


//Konstruktor
Labyrinth::Labyrinth(){
	labZeilen = kZeilen;
	labSpalten = kSpalten;
	labAnzGeister = 3;
	muenzen = 0;

	initialisieren();
}

int Labyrinth::getZeilen()
{
	return labZeilen;
}

int Labyrinth::getSpalten()
{
	return labSpalten;
}

int Labyrinth::getAnzGeister()
{
	return labAnzGeister;
}

int Labyrinth::getMuenzen()
{
	return muenzen;
}

//Freie Plätze werden mit muenzen belegt
void Labyrinth::legeMuenzen()
{
	for (int i = 0; i < labZeilen; i++)
	{
		for (int j = 0; j < labSpalten; j++)
		{
			if (lab[i][j] == ' ')
			{
				lab[i][j] = ';';
				muenzen++;
			}
		}
	}
}

void Labyrinth::zeichneChar(char c, Position pos)
{
	lab[pos.posy][pos.posx] = c;
}

void Labyrinth::zeichneChar(char c, Position posalt, Position posneu)
{
	lab[posneu.posy][posneu.posx] = c;
	lab[posalt.posy][posalt.posx] = ' ';
}

char Labyrinth::getZeichenAnPos(Position pos)
{
	return lab[pos.posy][pos.posx];
}

bool Labyrinth::istMuenzeAnPos(Position pos)
{
	if (lab[pos.posy][pos.posx] == ';')
		return true;
	else
		return false;
}

// Labyrinth als Textdatei speichern
void Labyrinth::exportDatei(char * dateiname) {
	ofstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) {
		datei << lab[i];
	}
	datei.close();
}

// Labyrinth als Textdatei einlesen
void Labyrinth::importDatei(char * dateiname) {
	ifstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) {
		datei.getline(lab[i], kSpalten + 2);
		lab[i][kSpalten] = '\n';
		lab[i][kSpalten + 1] = '\0';
	}
	datei.close();
}

// Labyrinth auf dem Bildschirm ausgeben
void Labyrinth::drucken() {
	// Console frei machen
	system("cls");
	// Labyrinth ausgeben
	for (int i = 0; i < labZeilen; i++)
	{
		//cout << *labyrinth;
		for (int j = 0; j < labSpalten + 1; j++)
			cout << lab[i][j];
	}
}
// Labyrinth mit # füllen
void Labyrinth::initialisieren() {
	for (int i = 0; i < labZeilen; i++)
	{
		for (int j = 0; j < labSpalten; j++)
			lab[i][j] = MAUER;
		lab[i][labSpalten] = '\n';
		lab[i][labSpalten + 1] = '\0';
	}

}
// Durch Herumlaufen werden Wege im Labyrinth erzeugt
// ASCII-Wert der Tasten: oben 72, links 75, rechts 77, unten 80
void Labyrinth::erzeugen() {
	char c = 'x';
	int posx = labSpalten / 2;
	int posy = labZeilen / 2;
	lab[posy][posx] = ICH;
	drucken();
	while (c != 'q') {
		drucken();
		cout << "Laufen mit Pfeiltasten. Beenden mit q." << endl;
		lab[posy][posx] = WEG;
		c = _getch();
		switch (int(c)) {
			// oben
		case 72: posy = Max(1, posy - 1); break;
			// links
		case 75: posx = Max(1, posx - 1); break;
			// rechts
		case 77: posx = Min(labSpalten - 2, posx + 1); break;
			// unten
		case 80: posy = Min(labZeilen - 2, posy + 1); break;
			// q = quit
		case 113: break;
		}
		lab[posy][posx] = ICH;
	}
}

// Hilfsfunktion max
int Labyrinth::Max(int x, int y) {
	return (x <= y) ? y : x;
}

// Hilfsfunktion min
int Labyrinth::Min(int x, int y) {
	return (x <= y) ? x : y;
}
