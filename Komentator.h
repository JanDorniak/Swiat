#pragma once
#include <string>
#include <vector>
#include "Organizm.h"
using namespace std;

#define INFO_ROZMNAZANIE 0 //0 - jesli komentator ma nie dodawac komentarza o rozmnazaniu, 1 - przeciwnie

class Komentator
{
private:
	vector<string> rejestr;

	string odmienAtakujacego(char symbol); //odmiena do odpowiedniej formy np "Wilk" na "Wilka"
	string odmienBroniacego(char symbol);
protected:
public:
	Komentator();
	~Komentator();

	void komentujAkcje(int wynik, Organizm*, Organizm*); //dodaje do rejestru komentarz o akcji
	void czyscRejestr(); //czysci rejestr z poprzedniej tury
	void wypisz() const; //wypisuje zawartosc rejestru
};

