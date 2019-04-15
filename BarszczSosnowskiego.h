#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina
{
private:
protected:
public:
	BarszczSosnowskiego() = default;
	BarszczSosnowskiego(int x, int y, Swiat* swiat);

	void akcja() override;
	int kolizja(Organizm& atakujacy) override;
};
