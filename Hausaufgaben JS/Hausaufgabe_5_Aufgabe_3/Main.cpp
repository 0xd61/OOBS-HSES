#include <iostream>
#include "MyVector.h"
#include "Circle.h"
using namespace std;

unsigned int ObjectCounter::maxID = 0;
unsigned int ObjectCounter::number = 0;

int main() 
{
	MyVector v1;
	Point p1(1, 1);
	Point p2(2, 2);
	Point p3(3, 3);
	Point p4(4, 4);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);


	v1.at(1).print();
	v1.at(2).print();
	v1.at(1) = v1.at(2);
	v1.print();
	MyVector v2(v1);
	v2.print();
	dynamic_cast<Point&>(v1.at(2)).move(10, 10);
	v1.print();
	v2.print();
	cout << "Groesse von v1: " << v1.size();
	cout << "  Kapazitaet von v1: " << v1.capacity() << endl;
	if (!v1.empty()) {
		v1.clear();
	}
	cout << "Groesse von v1: " << v1.size();
	cout << "  Kapazitaet von v1: " << v1.capacity() << endl;
	v1.print();
	v2.print();
	cout << "Groesse von v2: " << v2.size();
	cout << "  Kapazitaet von v2: " << v2.capacity() << endl;
	v2.push_back(p1);
	cout << "Groesse von v2: " << v2.size();
	cout << "  Kapazitaet von v2: " << v2.capacity() << endl;
	v2.print();
	v1.push_back(p1);
	v2.append(v1);
	v1.print();
	v2.print();
	cout << "Kreise: " << endl;
	MyVector v3;
	Circle c1(p1, 1);
	Circle c2(p2, 2);
	v3.push_back(c1);
	v3.push_back(c2);
	v3.print();

	getchar();
	getchar();

	return 0;
}
