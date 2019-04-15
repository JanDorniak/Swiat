#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
private:
protected:
public:
	Lis() = default;
	Lis(int, int, Swiat*);

	void akcja() override;
	bool znajdzSlabszego(); //sprawdza czy w okolicy jest slabszy organizm
};

