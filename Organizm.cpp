#include "Organizm.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Organizm::Organizm(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol_na_planszy = symbol;
	this->swiat = swiat;
	this->polozenie_x = x;
	this->polozenie_y = y;
	this->narodziny = swiat->getTura();
}

void Organizm::zapiszSie(fstream& plik)
{
	plik << symbol_na_planszy << ' ';
	plik << polozenie_x << ' ';
	plik << polozenie_y << ' ';
	plik << narodziny << ' ';
	plik << sila << ' ';
}

void Organizm::wczytajSie(fstream& plik)
{
	plik >> narodziny;
	plik >> sila;
}

void Organizm::rysuj() const
{
	cout << symbol_na_planszy;
}

void Organizm::zabij() 
{
	swiat->przygotujDoUsuniecia(polozenie_x, polozenie_y); //ususwa z listy
	swiat->plansza->usun(polozenie_x, polozenie_y); //i z planszy
}

void Organizm::rozmnazaj()
{
	int zmianax = 0, zmianay = 0;

	if (!swiat->plansza->czyWolneWokol(polozenie_x, polozenie_y)) //jesli nie ma miejsca na potomka wokol
		return;

	do
	{
		zmianax = rand() % 3 - 1;
		if (zmianax == 0)
			zmianay = rand() % 3 - 1;
	} while (!swiat->plansza->czyWolne(polozenie_x + zmianax, polozenie_y + zmianay));

	swiat->dodajOrganizm(symbol_na_planszy, polozenie_x + zmianax, polozenie_y + zmianay);
}

int Organizm::getSila() const
{
	return sila;
}

int Organizm::getInicjatywa() const
{
	return inicjatywa;
}

int Organizm::getX() const
{
	return polozenie_x;
}

int Organizm::getY() const
{
	return polozenie_y;
}

int Organizm::getWiek() const
{
	return narodziny;
}

char Organizm::getSymbol() const
{
	return symbol_na_planszy;
}
