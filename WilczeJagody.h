#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina
{
private:
protected:
public:
	WilczeJagody() = default;
	WilczeJagody(int x, int y, Swiat* swiat);

	int kolizja(Organizm&) override;
};

