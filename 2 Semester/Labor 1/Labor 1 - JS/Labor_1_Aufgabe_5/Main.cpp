#include <cmath>

#define DEGREE_TO_RADIAN(degree) ((degree*3.14159f) / 180.0f)

float trapezFlaeche(float a, float b = 4.0f, float winkel = 90.0f , float c = 0.0f)
{
	return(0.5f * (a+c) * b * sin(DEGREE_TO_RADIAN(winkel)));
}

int main()
{
	float a = trapezFlaeche(2.0f, 4.0f, 45.0f, 3.5f);
	float b = trapezFlaeche(3.0f, 4.0f ,45.0f);
	float c = trapezFlaeche(4.0f, 5.0f);
	float d = trapezFlaeche(2.0f);

	return(0);
}