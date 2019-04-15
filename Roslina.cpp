#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int sila, char symbol, int x, int y, Swiat* swiat) : Organizm(sila, 0, symbol, x, y, swiat)
{

}

void Roslina::akcja()
{
	int szansa = rand() % 100;
	if (szansa < SZANSA)
		rozmnazaj();
}

int Roslina::kolizja(Organizm& atakujacy)
{
	//swiat->komentator.komentujAkcje(1, *this, atakujacy);
	//zabij();
	return 1;
}
