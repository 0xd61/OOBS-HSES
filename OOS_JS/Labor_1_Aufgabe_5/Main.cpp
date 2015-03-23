#include <cmath>


float trapezFlaeche(float a, float b = 1.0f, float winkel = 90.0f , float c = 1.0f)
{
	return(0.5f * (a+c) * b * sin(winkel));
}

int main()
{
	float a = trapezFlaeche(2.0f, 4.0f, 45.0f, 3.5f);
	float b = trapezFlaeche(3.0f, 4.0f ,45.0f);
	float c = trapezFlaeche(4.0f, 5.0f);
	float d = trapezFlaeche(2.0f);

	return(0);
}