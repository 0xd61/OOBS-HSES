#pragma once
class Kunde
{
	public:
		Kunde(char *Name, char *Ort, int *Alter);
		Kunde(const Kunde* kunde);
		~Kunde();

		void kaufe(double u);
		void print();

	public:
		static int getAnzahl();

	private:
		char *name;
		char *ort;
		int *alter;
		double umsatz;
		int transaktion;
		int id;
		static int anzahl;
};

