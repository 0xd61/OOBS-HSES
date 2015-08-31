#include <iostream>
using namespace std;

class A 
{
	int alpha;

	public:
		A()
		{
			cout << "Defaultkonstruktor von Klasse A" << endl;
		};

		A(int alpha) : alpha(alpha)
		{
			cout << "Konstruktor von Klasse A" << endl;
		}

		void print()
		{
			cout << "A - print:" << endl;
			cout << "A::alpha= " << alpha << endl;
		}
};

class B : virtual public A 
{
	int beta;

	public:
		B(int alpha, int beta) :A(alpha), beta(beta)
		{
			cout << "Konstruktor von Klasse B" << endl;
		}
		void print()
		{
			cout << "B - print:" << endl;
			A::print();
			cout << "B::beta= " << beta << endl;
		}
};

class C : virtual public A 
{
	int gamma;
	public:
		C(int alpha, int gamma) :A(alpha), gamma(gamma)
		{
			cout << "Konstruktor von Klasse C" << endl;
		}

		void print() 
		{
			cout << "C - print:" << endl;
			A::print();
			cout << "C::gamma= " << gamma << endl;
		}
};

class D : public B, public C 
{
	int delta;

	public:

		D(int alpha, int beta, int gamma, int delta)
			: A(alpha), B(alpha, beta), C(alpha, gamma), delta(delta)
		{
			cout << "Konstruktor von Klasse D" << endl;
		}

		void print() 
		{
			cout << "D - print:" << endl;
			B::print();
			C::print();
			cout << "D::delta= " << delta << endl;
		}
};

void main() 
{
	cout << "Deklaration von a ..." << endl;
	A a(1);

	cout << "Deklaration von b ..." << endl;
	B b(2, 3);

	cout << "Deklaration von c ..." << endl;
	C c(4, 5);

	cout << "Deklaration von d ..." << endl;
	D d(11, 12, 13, 14);

	A *v[4] = { &a, &b, &c, &d };
	cout << "Ausgabe von a.print():" << endl;
	a.print();
	cout << "Ausgabe von b.print():" << endl;
	b.print();
	cout << "Ausgabe von c.print():" << endl;
	c.print();
	cout << "Ausgabe von d.print():" << endl;
	d.print();
	cout << "Ausgabe von d.A::print():" << endl;
	d.A::print();
	cout << "Ausgabe mit erster Schleife" << endl;
	for (int i = 0; i < 4; i++)
		v[i]->print();

	C *w[2] = { &c, &d };

	cout << "Ausgabe mit zweiter Schleife" << endl;
	for (int i = 0; i < 2; i++)
		w[i]->print();

	cout << "Ausgabe mit Konvertierung" << endl;
	((D*)w[1])->print();

}
