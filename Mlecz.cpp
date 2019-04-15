#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(int x, int y, Swiat* swiat) : Roslina(0, 'M', x, y, swiat)
{

}

void Mlecz::akcja()
{
	Roslina::akcja();
	Roslina::akcja();
	Roslina::akcja();
}