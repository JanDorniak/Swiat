#include "Guarana.h"
#include "Zwierze.h"
#include "Swiat.h"

Guarana::Guarana(int x, int y, Swiat* swiat) : Roslina(0, 'G', x, y, swiat)
{

}

int Guarana::kolizja(Organizm& atakujacy)
{
	Zwierze& nowy = dynamic_cast<Zwierze&>(atakujacy);
	nowy.setSila(nowy.getSila() + 3); //zwieksza sile "zjadacza"

	return 1;
}