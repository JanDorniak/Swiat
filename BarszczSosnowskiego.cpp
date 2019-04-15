#include "BarszczSosnowskiego.h"
#include "Swiat.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat) : Roslina(10, 'B', x, y, swiat)
{

}

void BarszczSosnowskiego::akcja()
{
	Organizm** sasiedzi = swiat->plansza->getSasiedzi(polozenie_x, polozenie_y); //znajduje wszystkich sasiadow
	for (int i = 0; i < 4; i++)
	{
		if (sasiedzi[i] != nullptr && dynamic_cast<Roslina*>(sasiedzi[i]) == NULL) //zaabija sasiadow (rosliny nie)
		{ 
			swiat->komentator.komentujAkcje(1, sasiedzi[i], this);
			sasiedzi[i]->zabij();
		}
	}
	Roslina::akcja();

	delete[] sasiedzi;
}

int BarszczSosnowskiego::kolizja(Organizm& atakujacy) //jesli ktos ja zje to oboje umieraja
{
	swiat->komentator.komentujAkcje(0, this, &atakujacy);
	zabij();
	return 0;
}