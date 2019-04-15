#pragma once
#include "Plansza.h"
#include "Komentator.h"
#include "Enumy.h"
#include <list>


#define POCZATKOWA_ILOSC 2

class Swiat
{
private:
	int tura; //ktora tura
	std::list<Organizm*> lista; //lista organizmow posortowana
	//wg inicjatywy
protected:
public:
	Swiat(int x, int y); //konstrukror swiata o wymiarach XxY
	~Swiat(); //niszczenie calosic 

	Plansza* plansza; //plansza zawiera wskazniki na organizmy (nullptr jesli pole puste)
	Komentator komentator;

	void dodajOrganizm(char nazwa, int = -1, int = -1);
	void dodajDoListy(Organizm* organizm);// to do konstruktora
	void przygotujDoUsuniecia(int x, int y);
	void losujMiejsce(int&, int&);
	void iniciujOrganizmy();
	void wykonajTure(); //ma wykonywac ture
	void rysujSwiat(); //rysuje plansze (mozna dodac komentarze o sytuacjach)
	void wyswietlRejestr();
	void zapiszGre();
	void wczytajGre();
	int getTura();
	bool otworzPlik(fstream&, int);
};