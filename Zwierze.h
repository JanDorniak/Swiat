#pragma once
#include "Organizm.h"
#include <cstdlib> //losowanie

class Zwierze : public Organizm
{
private:

public:
	Zwierze() = default;
	Zwierze(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat);
	virtual ~Zwierze() = default;

	virtual void akcja() override; //proba ruchu
	virtual int kolizja(Organizm& atakujacy) override; //zwraca ...
	void interpretujWynik(int, int, Organizm*);
	void zmienWspolrzedne(int kierunek);
	void setSila(int);
	virtual int wybierzKierunek();

};