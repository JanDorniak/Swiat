#include "Komentator.h"
#include "Roslina.h"
#include "Swiat.h"
#include <iostream>
#include <string>
using namespace std;



Komentator::Komentator()
{
}


Komentator::~Komentator()
{
}

void Komentator::komentujAkcje(int wynik, Organizm* broniacy, Organizm* atakujacy)
{
	string atak = odmienAtakujacego(atakujacy->getSymbol());
	string obrona = odmienBroniacego(broniacy->getSymbol());
	if (atak == " " || obrona == " ")
		return;

	string zdanie = odmienAtakujacego(atakujacy->getSymbol());
	if (dynamic_cast<Roslina*>(broniacy) != nullptr)
		zdanie += " zjada ";
	else if (broniacy->getSymbol() == atakujacy->getSymbol())
	{ 
		if (INFO_ROZMNAZANIE)
			zdanie += " spotyka ";
		else return;
	}
	else
		zdanie += " atakuje ";
	zdanie += odmienBroniacego(broniacy->getSymbol());

	if (wynik == 1)
		zdanie += " i zyje dalej (";
	else if (wynik == 0)
		zdanie += " i umiera (";
	else
		zdanie += " i pozostaje na swoim miejscu (";

	zdanie += to_string(atakujacy->getY() + 1);
	zdanie += ',';
	zdanie += to_string(atakujacy->getX() + 1);
	zdanie += ')';

	rejestr.push_back(zdanie);
}

void Komentator::czyscRejestr()
{
	rejestr.clear();
}

void Komentator::wypisz()
{
	for (int i = 0; i < rejestr.size(); i++)
		cout << rejestr[i] << endl;
}

string Komentator::odmienAtakujacego(char symbol)
{
	string odmieniona_nazwa;
	switch (symbol)
	{
	case WILK:
		odmieniona_nazwa = "Wilk";
		break;
	case OWCA:
		odmieniona_nazwa = "Owca";
		break;
	case LIS:
		odmieniona_nazwa = "Lis";
		break;
	case ZOLW:
		odmieniona_nazwa = "Zolw";
		break;
	case ANTYLOPA:
		odmieniona_nazwa = "Antylopa";
		break;
	case CZLOWIEK:
		odmieniona_nazwa = "Czlowiek";
		break;
	case BARSZCZSOSNOWSKIEGO:
		odmieniona_nazwa = "Barszcz Sosnowskiego";
		break;
	default:
		odmieniona_nazwa = " ";
	}

	return odmieniona_nazwa;
}

string Komentator::odmienBroniacego(char symbol)
{
	string odmieniona_nazwa;
	switch (symbol)
	{
	case WILK:
		odmieniona_nazwa = "Wilka";
		break;
	case OWCA:
		odmieniona_nazwa = "Owce";
		break;
	case LIS:
		odmieniona_nazwa = "Lisa";
		break;
	case ZOLW:
		odmieniona_nazwa = "Zolwia";
		break;
	case ANTYLOPA:
		odmieniona_nazwa = "Antylope";
		break;
	case CZLOWIEK:
		odmieniona_nazwa = "Czlowieka";
		break;
	case TRAWA:
		odmieniona_nazwa = "Trawe";
		break;
	case MLECZ:
		odmieniona_nazwa = "Mlecza";
		break;
	case GUARANA:
		odmieniona_nazwa = "Guarane";
		break;
	case WILCZEJAGODY:
		odmieniona_nazwa = "Wilcze Jagody";
		break;
	case BARSZCZSOSNOWSKIEGO:
		odmieniona_nazwa = "Barszcz Sosnowskiego";
		break;
	default:
		odmieniona_nazwa = " ";
	}

	return odmieniona_nazwa;
}
