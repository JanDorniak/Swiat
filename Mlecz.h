#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
private:
protected:
public:
	Mlecz() = default;
	Mlecz(int x, int y, Swiat* swiat);

	void akcja();
};
