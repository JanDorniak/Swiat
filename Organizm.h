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
public:
	Organizm() = default;
	Organizm(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat);
	virtual ~Organizm() = default;

	virtual void akcja() = 0;
	virtual int kolizja(Organizm&) = 0;
	virtual void zapiszSie(std::fstream& plik);
	virtual void wczytajSie(std::fstream& plik);
	void rysuj(); //rysuje symbol organizmu na planszy
	void zabij(); //zabija organizm ktory to wywola
	void rozmnazaj();
	int getSila();
	int getInicjatywa();
	int getX();
	int getY();
	int getWiek();
	char getSymbol();
};
