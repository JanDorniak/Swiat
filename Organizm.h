#pragma once
#include <fstream>

class Swiat;

class Organizm
{
private:
protected:
	int sila, inicjatywa;
	int narodziny;
	char symbol_na_planszy;
	int polozenie_x, polozenie_y;
	Swiat* swiat;  

	void rozmnazaj();
public:
	Organizm() = default;
	Organizm(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat);
	virtual ~Organizm() = default;

	virtual void akcja() = 0;
	virtual int kolizja(Organizm& atakujacy) = 0; //zwraca 1 jesli walka wygrana 0 jesi przegrana, -1 jesli rozmnazanie
	virtual void zapiszSie(std::fstream& plik);
	virtual void wczytajSie(std::fstream& plik);
	void zabij(); //zabija organizm ktory to wywola
	void rysuj() const;
	int getSila() const;
	int getInicjatywa() const;
	int getX() const;
	int getY() const;
	int getWiek() const;
	char getSymbol() const;
};
