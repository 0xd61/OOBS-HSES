// Vergleich von Deklaration, Enumeration und Typumwandlung 
// in C und C++

// Fehler                                               C    |  C++
enum class enumeration { Place_1st, Place_2nd, Place_3rd, Place_4th };     // Z1           |  Bezeichner dürfen nicht mit einer Zahl anfangen.
enum class marks { A = '1', B = '2', C = '3', D = '4', E = '5', F = '6' }; // Z2           | Bezeichner dürfen nicht aus chars bestehen.
enum class class1 { DIETER, HANS, PETER, KAI };    // Z3           |
enum class class2 { ANDREA, SABINE, ZOE };    // Z4           |  Kai musste gelöscht werden, weil der Bezeichner sonst zwei mal existiert.
enum class sports { FUSSBALL, BASKETBALL, HOCKEY };// Z5           |

int main(void)                               // Z7           |
{
	int i;                                   // Z8           |
	sports mysport;                          // Z9           | 
	//enum sports mysport;                     // Z10          |  In C++ muss man den Typ nicht mehr mit Prefix schreiben.
	mysport = sports::FUSSBALL;                      // Z11          |
	//mysport = sports(FUSSBALL + sports(1));                  // Z12          | Nicht mehr möglich.
	mysport = sports(1);                             // Z13          |
	mysport = sports(10);                            // Z14          | Umwandlung benötigt.
	//mysport = sports(mysport + 1);                   // Z15          | Nicht mehr möglich.
	//mysport = sports(mysport + 1);           // Z16          | Nicht mehr möglich.
	float f;                                 // Z17          | 
	for (i = int(sports::FUSSBALL); i <= int(sports::HOCKEY); i++)     // Z18          | Konvertierung in int notwendig.
		mysport = sports(i);                 // Z19          | 
	for (int k = int(sports::FUSSBALL); k <= int(sports::HOCKEY); k++) // Z20          | Konvertierung in int notwendig.
		mysport = sports(k);                 // Z21          | 
	return 0;                                // Z22          |
}

