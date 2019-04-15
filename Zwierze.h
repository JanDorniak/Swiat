#pragma once
#include "Organizm.h"
#include <cstdlib>

class Zwierze : public Organizm
{
private:
protected:
	virtual int wybierzKierunek();
	void interpretujWynik(int wynik, int kierunek, Organizm*);
	void zmienWspolrzedne(int kierunek);
public:
	Zwierze() = default;
	Zwierze(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat);
	virtual ~Zwierze() = default;

	virtual void akcja() override;
	virtual int kolizja(Organizm& atakujacy) override; //zwraca 1 jesli walka wygrana 0 jesi przegrana, -1 jesli rozmnazanie
	void setSila(int n);
};