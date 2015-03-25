#include <iostream>
#include <cmath>

using namespace std;

float trapezFlaeche(float a, float b = 4.0f, float angle = 90.0f, float c = 0.0f)
{
	
	return (1.0f/2.0f) * (a + c) * b * sin(angle*3.14159265/180.0f);
}
int main()
{
	float a, b, c, d;
	//a
	a = trapezFlaeche(2.0f, 4.0f, 45.0f, 3.5f);
	//b
	b = trapezFlaeche(3.0f, 4.0f, 45.0f);
	//c
	c = trapezFlaeche(4.0f, 5.0f);
	//d
	d = trapezFlaeche(2.0f);

	getchar();
	return 0;
}