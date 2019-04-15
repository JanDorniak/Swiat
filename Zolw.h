#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze
{
private:
protected:
public:
	Zolw() = default;
	Zolw(int, int, Swiat*);

	void akcja() override;
	int kolizja(Organizm& atakujacy) override;
};
