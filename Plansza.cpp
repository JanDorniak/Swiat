#include "Plansza.h"
#include "Organizm.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Plansza::Plansza(int x, int y)
{
	this->x = x;
	this->y = y;
	pole_gry = new Organizm**[x];
	for (int i = 0; i < x; i++)
		pole_gry[i] = new Organizm*[y];
	iniciuj();
}

Plansza::~Plansza()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			delete pole_gry[i][j];
		delete[] pole_gry[i];
	}
	delete[] pole_gry;
}

void Plansza::rysuj() const
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (pole_gry[i][j] == nullptr)
				cout << PUSTE_POLE;
			else
				pole_gry[i][j]->rysuj();
		}
		cout << endl;
	}
}

void Plansza::iniciuj()
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			pole_gry[i][j] = nullptr;
}

void Plansza::umiesc(Organizm* organizm, int x, int y)
{
	pole_gry[x][y] = organizm;
}

void Plansza::usun(int x, int y)
{
	delete pole_gry[x][y];
	pole_gry[x][y] = nullptr;
}

int Plansza::getX() const
{
	return x;
}

int Plansza::getY() const
{
	return y;
}

bool Plansza::czyWolne(int x, int y)
{
	if (x >= this->x || y >= this->y || x < 0 || y < 0)
		return false;
	if (pole_gry[x][y] == nullptr)
		return true;
	return false;
}

bool Plansza::czyWolneWokol(int x, int y)
{
	if (czyWolne(x + 1, y) || czyWolne(x - 1, y) || czyWolne(x, y + 1) || czyWolne(x, y - 1))
		return true;
	return false;
}

Organizm* Plansza::getOrganizm(int x, int y) //nie uzywane?
{
	if (x >= this->x || y >= this->y || x < 0 || y < 0)
		return nullptr;
	return pole_gry[x][y];
}

Organizm** Plansza::getSasiedzi(int x, int y)
{
	Organizm** sasiedzi = new Organizm*[4];
	sasiedzi[0] = getOrganizm(x + 1, y);
	sasiedzi[1] = getOrganizm(x - 1, y);
	sasiedzi[2] = getOrganizm(x, y + 1);
	sasiedzi[3] = getOrganizm(x, y - 1);

	return sasiedzi;
}

Organizm* Plansza::przesun(int x, int y, int kierunek)
{
	int zmianay=0, zmianax=0;
	if (kierunek == LEWO)
		zmianax = -1;
	else if (kierunek == PRAWO)
		zmianax = 1;
	else if (kierunek == GORA)
		zmianay = 1;
	else
		zmianay = -1;

	if ((czyWolne(x+zmianax,y+zmianay))) //jesli pole jest wolne zwraca null
	{ 
		pole_gry[x + zmianax][y + zmianay] = pole_gry[x][y];
		pole_gry[x][y] = nullptr;
		return nullptr; 
	}
	else // jesli nie to zwraca organizm
	{ 
		return pole_gry[x + zmianax][y + zmianay];
	}

}
