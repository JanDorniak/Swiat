#pragma once
#include "Organizm.h"
#include <cstdlib>

#define SZANSA 4 //szansa na rozmnozenie sie rosliny

class Roslina : public Organizm
{
private:
protected:
public:
	Roslina() = default;
	Roslina(int sila, char symbol, int x, int y, Swiat* swiat);
	virtual ~Roslina() = default;

	virtual void akcja() override;
	virtual int kolizja(Organizm& atakujacy) override;
};
