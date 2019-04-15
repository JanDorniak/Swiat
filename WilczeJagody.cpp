#include "WilczeJagody.h"
#include "Swiat.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat) : Roslina(99, 'J', x, y, swiat)
{

}

int WilczeJagody::kolizja(Organizm& atakujacy)
{
	swiat->komentator.komentujAkcje(0, this, &atakujacy);
	zabij();
	return 0;
}