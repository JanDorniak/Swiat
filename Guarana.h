#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
private:
protected:
public:
	Guarana() = default;
	Guarana(int x, int y, Swiat* swiat);

	int kolizja(Organizm& atakujacy) override;
};
