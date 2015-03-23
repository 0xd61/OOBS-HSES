/*

Spiel Tsching, Tschang, Tschong

Regeln:
Es gibt zwei Spieler: der Programmierer und der Computer.
Beide Spieler waehlen gleichzeitig eines der drei Objekte
Stein, Schere und Papier. Beide können das gleiche Objekt wählen.
Der Spieler, der das mächtigere Objekt gewählt hat gewinnt.
SCHERE kann einen STEIN nicht zerschneiden, d.h. STEIN ist
mächtiger als SCHERE. PAPIER wickelt STEIN ein, d.h. PAPIER ist
mächtiger als STEIN. SCHERE zerschneidet PAPIER, d. h. SCHERE
ist maechtiger als PAPIER

*/

#define stringify( name ) # name

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

// Aufzählungstyp für Stein etc.
enum objectType { STEIN, SCHERE, PAPIER };

// Struktur für einen Spieler bestehend aus Name und Wahl 
// des Spielers
struct player {
	char * name;
	objectType choice;
};

// Variable für den Namen des Spielers 
char name[15];

// Name des Spielers eingeben
char * enterName(char str[])
{
	cout << endl << "Name des Spielers: ";
	cin >> str;

	return name;
}

// Den Computer zufällig waehlen lassen. 
// Nutzen Sie srand(...) und rand().
objectType randomChoice()
{
	
	return objectType(rand() % 3);
}

// Die Wahl von STEIN etc. als String zurückgeben lassen
char * object2str(objectType o)
{
	return (char*)(o);
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(player p)
{
	char  *choiceToString = nullptr;

	switch (p.choice)
	{
		case SCHERE: choiceToString = "Schere"; break;
		case STEIN: choiceToString = "Stein"; break;
		case PAPIER: choiceToString = "Papier"; break;
	}

	cout << endl << p.name << " hat das Objekt " << choiceToString << " gewaehlt." << endl;
}

// Die Wahl des Spielers abfragen
objectType enterChoice()
{
	int choice = 0;
	
	cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
	cin >> choice;

	return objectType(choice-1);
}

// Die Wahl bestimmen, die gewonnen hat
objectType winningObject(objectType obj1, objectType obj2)
{
	//Stein schlägt Schere
	//Schere schlägt Papier
	//Papier schlägt Stein

	bool obj1Winner = ((obj1 == STEIN) && (obj2 == SCHERE)) || ((obj1 == SCHERE) && (obj2 == PAPIER)) || ((obj1 == PAPIER) && (obj2 == STEIN));
	bool obj2Winner = ((obj2 == STEIN) && (obj1 == SCHERE)) || ((obj2 == SCHERE) && (obj1 == PAPIER)) || ((obj2 == PAPIER) && (obj1 == STEIN));

	if (obj1Winner)
	{
		return(obj1);
	}

	if (obj2Winner)
	{
		return(obj2);
	}

	//TODO: Unentschieden muss mit rein.
	return(obj2);
}

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{
	objectType winningObj = winningObject(p1.choice, p2.choice);

	if (winningObj == p1.choice)
	{
		cout << endl << p1.name << " hat gewonnen!" << endl << endl;
	}
	else
	{
		cout << endl << p2.name << " hat gewonnen!" << endl << endl;
	}
}

int main()
{
	player player1, player2;
	
	player1.name = "Computer";
	player1.choice = randomChoice();
	cout << "Der Computer hat sein Wahl getroffen." << endl;
	
	player2.name = enterName(name);
	player2.choice = enterChoice();
	
	showPlayer(player1);
	showPlayer(player2);
	
	showWinner(player1, player2);
}


