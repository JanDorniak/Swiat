#include "Czlowiek.h"
#include "Swiat.h"
#include <conio.h>
#include <iostream>

Czlowiek::Czlowiek(int x, int y, Swiat* swiat) : Zwierze(5, 4, 'C', x, y, swiat)
{
	tura_uzycia = 0;
}

void Czlowiek::akcja()
{
	if (swiat->getTura() - tura_uzycia < 5 && tura_uzycia != 0) //jesli uzyto nie dawniej niz 5 tur temu to uzyj umiejetnosci
		calopalenie();

	int kierunek = wybierzKierunek();
	int wynik_walki = -2;

	Organizm* przeciwnik = swiat->plansza->przesun(polozenie_x, polozenie_y, kierunek);
	if (przeciwnik != nullptr)
	{
		wynik_walki = przeciwnik->kolizja(*this);
		interpretujWynik(wynik_walki, kierunek, przeciwnik);
	}
	else 
	{
		zmienWspolrzedne(kierunek);
	}

	if ((wynik_walki == 1 || wynik_walki == -2) && swiat->getTura() - tura_uzycia < 5 && tura_uzycia != 0) //uzycie umiejetnosci po ruchu
		calopalenie();
}

void Czlowiek::calopalenie()
{
	Organizm** sasiedzi = swiat->plansza->getSasiedzi(polozenie_x, polozenie_y);
	for (int i = 0; i < 4; i++)
	{
		if (sasiedzi[i] != nullptr)
		{
			swiat->komentator.komentujAkcje(1, sasiedzi[i], this);
			sasiedzi[i]->zabij();
		}
	}

	delete[] sasiedzi;
}

void Czlowiek::informujORuchu()
{
	system("cls");
	swiat->plansza->rysuj();
	cout << "Tura: " << swiat->getTura() << endl;
	cout << "Ruch gracza" << endl;
	cout << "Nacisnij strzalke aby sie poruszyc" << endl;
	if (tura_uzycia == 0 || swiat->getTura() - tura_uzycia >= 10)
		cout << "UMIEJETNOSC SPECJALNA DOSTEPNA" << endl;
	else if (swiat->getTura() - tura_uzycia < 5)
		cout << "UMIEJETNOSC SPECJALNA AKTYWNA" << endl;
	else
		cout << "UMIEJETNOSC SPECJALNA SIE LADUJE" << endl;
}

void Czlowiek::zapiszSie(fstream& plik)
{
	Organizm::zapiszSie(plik);
	plik << tura_uzycia;
}

void Czlowiek::wczytajSie(fstream& plik)
{
	Organizm::wczytajSie(plik);
	plik >> tura_uzycia;
}

int Czlowiek::wybierzKierunek() //wybor kierunku w ktory ma sie ruszyc
{
	int kierunek;

	do
	{
		informujORuchu();
		kierunek = _getch();
		if (kierunek == 72 && polozenie_x != 0)
			kierunek = LEWO;
		else if (kierunek == 80 && polozenie_x != swiat->plansza->getX() - 1)
			kierunek = PRAWO;
		else if (kierunek == 75 && polozenie_y != 0)
			kierunek = DOL;
		else if (kierunek == 77 && polozenie_y != swiat->plansza->getY() - 1)
			kierunek = GORA;
		else if (kierunek == 32 && (tura_uzycia == 0 || swiat->getTura() - tura_uzycia > 10))
		{
			tura_uzycia = swiat->getTura();
			calopalenie();
			kierunek = 0;
		}
		else
			kierunek = 0;
	} while (kierunek == 0);

	return kierunek;
}
