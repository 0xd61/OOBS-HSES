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
	cout << "Bitte Name eingeben: ";
	cin >> str;
	
	return str;
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
	switch (o)
	{
	case STEIN:
		return "Stein";
	case SCHERE:
		return "Schere";
	case PAPIER:
		return "Papier";
	default:
		return "ERROR";
	}


}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(player p)
{

	cout << p.name << " hat " << object2str(p.choice) << " gewaehlt." << endl << endl;
}

// Die Wahl des Spielers abfragen
objectType enterChoice()
{
	char Input;

	while (true)
	{
		cout << "Was moechtest du waehlen: ";
		cout << "[S]tein; Sch[e]re; [P]apier" << endl;

		cin >> Input;

		switch (Input)
		{
		case 'S':
		case 's':
			return STEIN;
		case 'E':
		case 'e':
			return SCHERE;
		case 'P':
		case 'p':
			return PAPIER;
		default:
			cout << "Ungueltiges Zeichen!" << endl << endl;
			break;
		}
	}

}

// Die Wahl bestimmen, die gewonnen hat
objectType winningObject(objectType obj1, objectType obj2)
{
	bool obj1Winner = (obj1 == STEIN && obj2 == SCHERE || obj1 == SCHERE && obj2 == PAPIER || obj1 == PAPIER && obj2 == STEIN);
	bool obj2Winner = (obj2 == STEIN && obj1 == SCHERE || obj2 == SCHERE && obj1 == PAPIER || obj2 == PAPIER && obj1 == STEIN);

	if (obj1Winner == true)
		return obj1;
	else
		return obj2;

}

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{
	
	objectType WinningObj = winningObject(p1.choice, p2.choice);

	if (WinningObj == p1.choice)
	{
		cout << p1.name << " hat gewonnen!" << endl;
	}
	else
	{
		cout << p2.name << " hat gewonnen!" << endl;
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

	fflush(stdin);
	getchar();
	return 1;
}


