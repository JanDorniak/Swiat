#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(int x, int y, Swiat* swiat) : Zwierze(4, 4, 'A', x, y, swiat)
{

}

void Antylopa::akcja()
{
	int kierunek = wybierzKierunek();

	Organizm* przeciwnik = swiat->plansza->przesun(polozenie_x, polozenie_y, kierunek);

	if (przeciwnik != nullptr)
	{
		int wynik_walki = przeciwnik->kolizja(*this);
		interpretujWynik(wynik_walki, kierunek, przeciwnik);
		if (wynik_walki == 1 || wynik_walki == -1) //jesli przezyla pierwszy krok to wykonuje kolejny
			Zwierze::akcja();
	}
	else
	{
		zmienWspolrzedne(kierunek);
		Zwierze::akcja();
	}
}

int Antylopa::kolizja(Organizm& atakujacy)
{
	int ucieczka = rand() % 2;
	if (ucieczka == 1 && atakujacy.getSymbol() != symbol_na_planszy && //na 50% ucieka + musi byc wolne miejsce + 
		swiat->plansza->czyWolneWokol(polozenie_x, polozenie_y))	   //nie ucieka jesli atakuje ten sam gatunek
	{
		Organizm* przeciwnik;
		int kierunek;
		do
		{
			kierunek = wybierzKierunek();
			przeciwnik = swiat->plansza->przesun(polozenie_x, polozenie_y, kierunek); 
		} while (przeciwnik != nullptr); //szuka wolnego pola az znajdzie
		zmienWspolrzedne(kierunek);
		return 1;
	}
	else
		Zwierze::kolizja(atakujacy); //jesli nie udalo sie uciec walczy
}