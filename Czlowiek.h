#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
	int tura_uzycia; // tura w ktorej ostatnio uzyto umiejetenosci

	void calopalenie(); // specjalna umiejetnosc
	void informujORuchu(); // informuje o koniecznosci ruchu i stanie umiejetnosci
	int wybierzKierunek() override;
protected:
public:
	Czlowiek() = default;
	Czlowiek(int, int, Swiat*);

	void akcja() override;
	void zapiszSie(std::fstream& plik) override; //musi miec swoje funkcje do zapisywania/wczytywania (ma jedna wiecej zmienna)
	void wczytajSie(std::fstream& plik) override;
};
