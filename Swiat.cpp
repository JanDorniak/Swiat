#include "Swiat.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Roslina.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdio>

using namespace std;

Swiat::Swiat(int x, int y)
{
	plansza = new Plansza(x, y);
	tura = 1;
	iniciujOrganizmy();
	rysujSwiat();
}

Swiat::~Swiat()
{
	delete plansza;
}

void Swiat::dodajOrganizm(char nazwa, int x, int y)
{
	if (x < 0 || y < 0)
		losujMiejsce(x, y);
	Organizm* nowy = nullptr;

	switch (nazwa)
	{
	case WILK:
		nowy = new Wilk(x, y, this);
		break;
	case OWCA:
		nowy = new Owca(x, y, this);
		break;
	case LIS:
		nowy = new Lis(x, y, this);
		break;
	case ZOLW:
		nowy = new Zolw(x, y, this);
		break;
	case ANTYLOPA:
		nowy = new Antylopa(x, y, this);
		break;
	case TRAWA:
		nowy = new Trawa(x, y, this);
		break;
	case MLECZ:
		nowy = new Mlecz(x, y, this);
		break;
	case GUARANA:
		nowy = new Guarana(x, y, this);
		break;
	case WILCZEJAGODY:
		nowy = new WilczeJagody(x, y, this);
		break;
	case BARSZCZSOSNOWSKIEGO:
		nowy = new BarszczSosnowskiego(x, y, this);
		break;
	case CZLOWIEK:
		nowy = new Czlowiek(x, y, this);
		break;
	}
	dodajDoListy(nowy);
	plansza->umiesc(nowy, x, y);
}

void Swiat::dodajDoListy(Organizm* organizm)
{
	if (lista.empty())
	{
		lista.push_front(organizm);
		return;
	}

	int flaga = 0;
	list<Organizm*>::iterator i;

	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (*i == nullptr) continue;
		if ((*i)->getInicjatywa() < organizm->getInicjatywa())
		{
			lista.insert(i, organizm);
			flaga = 1;
			break;
		}
	}
	if (flaga == 0)
		lista.push_back(organizm);
}

void Swiat::przygotujDoUsuniecia(int x, int y)
{
	list<Organizm*>::iterator i;

	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (*i == nullptr) continue;

		if ((*i)->getX() == x && (*i)->getY() == y)
		{
			*i = nullptr;
			break;
		}
	}
}

void Swiat::losujMiejsce(int&x, int& y)
{
	do 
	{
		x = rand() % plansza->getX();
		y = rand() % plansza->getY();
	} while (!(plansza->czyWolne(x, y)));
}

void Swiat::iniciujOrganizmy()
{
	char organizmy[]{ WILK,OWCA,LIS,ZOLW,ANTYLOPA,TRAWA,MLECZ,GUARANA, WILCZEJAGODY, BARSZCZSOSNOWSKIEGO };
	int rozmiar = sizeof(organizmy) / sizeof(char);
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < POCZATKOWA_ILOSC; j++)
			dodajOrganizm(organizmy[i]);
	}
	dodajOrganizm(CZLOWIEK);
}

void Swiat::wykonajTure()
{
	list<Organizm*>::iterator i;

	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (*i == nullptr) continue;

		if ((*i)->getWiek() != tura || tura == 1)
		{
			(*i)->akcja();
		}
	}
	lista.remove(nullptr);

	tura++;

	rysujSwiat();
	komentator.czyscRejestr();
}

void Swiat::rysujSwiat()
{
	char znak;

	system("cls");
	plansza->rysuj();
	cout << "Tura: " << tura << endl;
	cout << "Nacisnij enter aby kontynuowac, spacje aby wyswietlic raport z tury" << endl;
	cout << "Aby zapisac wcisnij S, aby wczytac wscisnij W" << endl;
	do
	{
		znak = _getch();
		if (znak == 32)
		{ 
			wyswietlRejestr();
			break;
		}
		else if (znak == 'S' || znak == 's')
		{
			zapiszGre();
			break;
		}
		else if (znak == 'W' || znak == 'w')
		{
			wczytajGre();
			break;
		}
	}
	while (znak != 13);
}

void Swiat::wyswietlRejestr()
{
	system("cls");
	cout << "Zdarzenia z poprzedniej tury: " << endl;
	komentator.wypisz();

	while (_getch() != 32);
	rysujSwiat();
}

void Swiat::zapiszGre()
{
	fstream zapis;

	if (!otworzPlik(zapis, 0))
	{ 
		rysujSwiat();
		return;
	}

	zapis << tura << endl;
	zapis << plansza->getX() << endl << plansza->getY() << endl;

	list<Organizm*>::iterator i;

	lista.remove(nullptr);
	for (i = lista.begin(); i != lista.end(); i++)
	{
		(*i)->zapiszSie(zapis);
		zapis << endl;
	}

	/*for (int i = 0; i < plansza->getX(); i++)
		for (int j = 0; j < plansza->getY(); j++)
		{
			organizm = plansza->getOrganizm(i,j);
			if (organizm == nullptr)
				zapis << '0' << endl;
			else
			{
				organizm->zapiszSie(zapis);
				zapis << endl;
			}
		}*/
	zapis.close();
	rysujSwiat();
}

void Swiat::wczytajGre()
{
	fstream zapis;
	char znak;
	int x, y;

	if (!otworzPlik(zapis, 1))
	{
		rysujSwiat();
		return;
	}

	delete plansza;
	lista.clear();

	zapis >> tura;
	zapis >> x;
	zapis >> y;

	plansza = new Plansza(x, y);

	while (!zapis.eof())
	{
		zapis >> znak;
		zapis >> x;
		zapis >> y;
		if (plansza->czyWolne(x,y))
			dodajOrganizm(znak, x, y);
		plansza->getOrganizm(x, y)->wczytajSie(zapis);
	} 

	/*for (int i = 0; i < plansza->getX(); i++)
		for (int j = 0; j < plansza->getY(); j++)
		{
			zapis >> znak;
			if (znak == '0')
				plansza->umiesc(nullptr, i, j);
			else
			{
				zapis >> x;
				zapis >> y;
				dodajOrganizm(znak, x, y);
				plansza->getOrganizm(x,y)->wczytajSie(zapis);
			}
		}*/
	zapis.close();
	rysujSwiat();
}

bool Swiat::otworzPlik(fstream& plik, int tryb) //0 zapis, 1 odczyt
{
	string nazwa;

	system("cls");
	cout << "Podaj nazwe zapisu: ";
	cin >> nazwa;
	nazwa += ".txt";

	if (tryb == 0)
		plik.open(nazwa, ios::out | ios::trunc);
	else
		plik.open(nazwa, ios::in);

	if (!plik.good())
	{
		cout << "Blad odczytu... , Nacisnij aby kontynuowac" << endl;
		_getch();
		return false;
	}
	return true;
}

int Swiat::getTura()
{
	return tura;
}
