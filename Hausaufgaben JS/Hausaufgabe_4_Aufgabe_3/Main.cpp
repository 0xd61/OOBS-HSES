#include "Akkubohrschrauber.h"

int main() 
{
	Akkubohrer b(300);
	b.print();
	Akkuschrauber s(500);
	s.print();
	Akkubohrschrauber bs(400, 900);
	bs.print();
	return 0;
}