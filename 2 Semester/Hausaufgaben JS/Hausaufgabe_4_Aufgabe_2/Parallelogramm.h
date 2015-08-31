#pragma once
class Parallelogramm
{
	public:
		Parallelogramm();
		Parallelogramm(const double a_value, const double b_value, const double winkel_value);
		~Parallelogramm();

		void print();

	public:
		void setA(const double a_value);
		void setB(const double b_value);
		void setWinkel(const double winkel_value);

		double getA() const;
		double getB() const;
		double getWinkel() const;

	protected:
		double a;
		double b;
		double winkel;
};

