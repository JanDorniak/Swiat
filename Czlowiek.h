#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
	int tura_uzycia; // tura w ktorej ostatnio uzyto umiejetenosci
protected:
public:
	Czlowiek() = default;
	Czlowiek(int, int, Swiat*);

	void akcja() override;
	void calopalenie(); // specjalna umiejetnosc
	void informujORuchu(); // informuje o koniecznosci ruchu i stanie umiejetnosci
	void zapiszSie(std::fstream& plik) override; //musi miec swoje funkcje do zapisywania/wczytywania (ma jedna wiecej zmienna)
	void wczytajSie(std::fstream& plik) override;
	int wybierzKierunek() override;
};
