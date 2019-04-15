#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
private:
protected:
public:
	Antylopa() = default;
	Antylopa(int, int, Swiat*);

	void akcja() override;
	int kolizja(Organizm& atakujacy) override;
};

