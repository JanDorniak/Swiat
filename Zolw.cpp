#include "Zolw.h"

Zolw::Zolw(int x, int y, Swiat* swiat) : Zwierze(2, 1, 'Z', x, y, swiat)
{

}

void Zolw::akcja()
{
	int czy_ruszac = rand() % 4;
	if (czy_ruszac == 3)
		Zwierze::akcja();
}

int Zolw::kolizja(Organizm& atakujacy)
{ 
	if (atakujacy.getSila() < 5)
		return -1;
	else
		Zwierze::kolizja(atakujacy);
}