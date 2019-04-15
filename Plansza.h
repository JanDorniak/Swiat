#pragma once
#include "Enumy.h"

#define PUSTE_POLE '.' //jaki znak ma byc na pustym polu

class Organizm;

class Plansza
{
private:
	int x, y; //wymiary
	Organizm*** pole_gry; //plansza wlasciwa
protected:
public:
	Plansza(int x, int y); //inicjalizacja
	~Plansza();

	void rysuj(); //rysowanie planszy
	void iniciuj(); //inicjuje nullami
	void umiesc(Organizm* organizm, int x, int y); //umieszcza nowy organizm (zwraca czy pole bylo puste)
	void usun(int x, int y); //zabija i czysci pamiec po organizmie
	int getX(); //zwraca wysokosc
	int getY(); //zwraca szereokosc
	bool czyWolne(int x, int y);
	bool czyWolneWokol(int x, int y);
	Organizm* getOrganizm(int x, int y);
	Organizm** getSasiedzi(int x, int y);
	Organizm* przesun(int x, int y, int kierunek); //przemieszcza organizm w danym kierunku zwraca przesuniety
	//organizm jesli pole jest zajete zeby mozna bylo uruchomic kolizje (jesli wolne zwraca nullptr)
};
