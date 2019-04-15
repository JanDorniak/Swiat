#include "Swiat.h"
#include <ctime>
#include <Windows.h>

int main()
{
	srand(time(NULL));
	SetConsoleTitle("Jan Dorniak, s175959");

	Swiat swiat(15, 25);

	while (1) 
		swiat.wykonajTure();

	return 0;
}