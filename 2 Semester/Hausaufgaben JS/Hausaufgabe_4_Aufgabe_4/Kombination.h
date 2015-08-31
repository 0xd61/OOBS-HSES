#pragma once
#include "Gefrierschrank.h"
#include "Kuehlschrank.h"

class Kombination : public Kuehlschrank, public Gefrierschrank
{
	public:
		Kombination();
		Kombination(const string name_value, const double gewicht_value, const double volumen_gs, const double volumen_ks);
		~Kombination();

		void print();
};

