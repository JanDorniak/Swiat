#include "Lis.h"
#include "Swiat.h"

Lis::Lis(int x, int y, Swiat* swiat) : Zwierze(3, 7, 'L', x, y, swiat)
{

}

void Lis::akcja()
{
	if (!(swiat->plansza->czyWolneWokol(polozenie_x, polozenie_y) || znajdzSlabszego())) //sprawdzanie czy jest mozliwy ruch
		return;

	int kierunek;
	Organizm* przeciwnik;
	do
	{
		kierunek = wybierzKierunek();
		przeciwnik = swiat->plansza->przesun(polozenie_x, polozenie_y, kierunek);
	} while (przeciwnik != nullptr && przeciwnik->getSila() > sila); //jesli ma mozliwy ruch szuka az znajdzie dogodne miejsce

	if (przeciwnik != nullptr)
	{
		int wynik_walki = przeciwnik->kolizja(*this);
		interpretujWynik(wynik_walki, kierunek, przeciwnik);
	}
	else
		zmienWspolrzedne(kierunek);
}

bool Lis::znajdzSlabszego()
{
	Organizm** sasiedzi = swiat->plansza->getSasiedzi(polozenie_x, polozenie_y);
	for (int i = 0; i < 4; i++)
	{
		if (sasiedzi[i] != nullptr && sasiedzi[i]->getSila() <= sila)
		{ 
			delete[] sasiedzi;
			return true;
		}
	}
	delete[] sasiedzi;
	return false;
}