#include "Zwierze.h"
#include "Swiat.h"


Zwierze::Zwierze(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat) : Organizm(sila,inicjatywa
,symbol,x,y,swiat)
{

}

void Zwierze::akcja()
{
	int kierunek = wybierzKierunek();

	Organizm* przeciwnik = swiat->plansza->przesun(polozenie_x, polozenie_y, kierunek);
	if (przeciwnik != nullptr) //jesli natrafi na przeciwnika
	{
		int wynik_walki = przeciwnik->kolizja(*this);
		interpretujWynik(wynik_walki, kierunek, przeciwnik);
	}
	else //jesli natrafi na puste pole
	{
		zmienWspolrzedne(kierunek);
	}
}

int Zwierze::kolizja(Organizm& atakujacy)
{
	if (atakujacy.getSymbol() == symbol_na_planszy) // jesli atakuje ten sam gatunek
	{
		rozmnazaj();
		return -1;
	}
	else if (atakujacy.getSila() >= sila) // jesli atakujacy wygrywa
	{
		return 1;
	}
	else // jesli atakujacy przegrywa
	{
		return 0;
	}
}

void Zwierze::interpretujWynik(int wynik, int kierunek, Organizm* przeciwnik)
{
	swiat->komentator.komentujAkcje(wynik, przeciwnik, this); //wyslanie sygnalu do komentatora
	if (wynik == 0) // walka przegrana
	{
		zabij();
		return;
	}
	else if (wynik == 1) // walka wygrana
	{
		przeciwnik->zabij();
		swiat->plansza->przesun(polozenie_x, polozenie_y, kierunek);
		zmienWspolrzedne(kierunek);
	}
	else if (wynik == -1) // rozmnazanie
	{
		return;
	}
}

void Zwierze::zmienWspolrzedne(int kierunek)
{
	if (kierunek == LEWO)
		polozenie_x--;
	else if (kierunek == PRAWO)
		polozenie_x++;
	else if (kierunek == DOL)
		polozenie_y--;
	else
		polozenie_y++;
}

void Zwierze::setSila(int n)
{
	sila = n;
}

int Zwierze::wybierzKierunek() 
{
	int kierunek = rand() % 4 + 1;
	if (kierunek == LEWO && polozenie_x == 0)
		return PRAWO;
	else if (kierunek == PRAWO && polozenie_x == swiat->plansza->getX() - 1)
		return LEWO;
	else if (kierunek == GORA && polozenie_y == swiat->plansza->getY() - 1)
		return DOL;
	else if (kierunek == DOL && polozenie_y == 0)
		return GORA;

	return kierunek;
}