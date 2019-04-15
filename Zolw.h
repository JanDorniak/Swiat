#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze
{
private:
protected:
public:
	Zolw() = default;
	Zolw(int x, int y, Swiat* swiat);

	void akcja() override;
	int kolizja(Organizm& atakujacy) override;
};
