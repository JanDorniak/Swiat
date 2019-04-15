#pragma once
#include "Enumy.h"

#define PUSTE_POLE '.' //jaki znak ma byc na pustym polu

class Organizm;

class Plansza
{
private:
	int x, y;
	Organizm*** pole_gry;

	void iniciuj(); //inicjuje nullami
protected:
public:
	Plansza(int x, int y);
	~Plansza();

	void rysuj() const; 
	void umiesc(Organizm* organizm, int x, int y); //umieszcza nowy organizm na planszy
	void usun(int x, int y); //usuwa i czysci pamiec po organizmie
	int getX() const; 
	int getY() const;
	bool czyWolne(int x, int y); //zwraca czy dane pole jest wolne
	bool czyWolneWokol(int x, int y); //zwraca czy jest wokol jakies wolne pole
	Organizm* getOrganizm(int x, int y);
	Organizm** getSasiedzi(int x, int y); //zwraca organizmy wokol
	Organizm* przesun(int x, int y, int kierunek); //przemieszcza organizm w danym kierunku zwraca przesuniety
	//organizm jesli pole jest zajete zeby mozna bylo uruchomic kolizje (jesli wolne zwraca nullptr)
};
