#pragma once
#include "Plansza.h"
#include "Komentator.h"
#include "Enumy.h"
#include <list>
using namespace std;


#define POCZATKOWA_ILOSC 2 //poczatkowa ilosc kazdego organizmu (oprocz czlowieka)

class Swiat
{
private:
	int tura; 
	list<Organizm*> lista; //lista organizmow posortowana wg inicjatywy

	void iniciujOrganizmy();
	void wyswietlRejestr(); //wyswietla zdarzenia z poprzedniej tury
	void rysujMenu();
	void zapiszGre();
	void wczytajGre();
	bool otworzPlik(fstream& plik, int tryb); //liczba oznacza tryby w jakim plik sie otworzy 1 - do oczytu, 0 - do zapisu
	void dodajDoListy(Organizm* organizm); //dodawanie organizmu do posortowanej listy
	void losujMiejsce(int& x, int& y);
protected:
public:
	Swiat(int x, int y); //konstrukror swiata o wymiarach XxY
	~Swiat();

	Plansza* plansza; //plansza zawiera wskazniki na organizmy (nullptr jesli pole puste)
	Komentator komentator;

	void dodajOrganizm(char nazwa, int x = -1, int y = -1); //dodawanie organizmu jesli x i y = -1 w losowe miejsce
	void przygotujDoUsuniecia(int x, int y); //przygotowanie organizmu do usniecia z listy (dopiero po turze)
	void wykonajTure(); 
	int getTura() const;
};