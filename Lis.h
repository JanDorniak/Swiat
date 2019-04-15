#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
private:
	bool znajdzSlabszego(); //sprawdza czy w okolicy jest slabszy organizm
protected:
public:
	Lis() = default;
	Lis(int x, int y, Swiat* swiat);

	void akcja() override;
};

