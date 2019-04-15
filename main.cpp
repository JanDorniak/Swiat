#include "Swiat.h"
#include <ctime>
//#include "vld.h"
//#include <vld.h>
#include <Windows.h>
using namespace std;

int main()
{
	srand(time(NULL));
	SetConsoleTitle("Jan Dorniak, s175959");
	Swiat swiat(15, 25);

	while (swiat.getTura() != 1000)
	{
		swiat.wykonajTure();
	}

	return 0;
}

//dodac wyjscie z gry
//przeniesc enumy
//dodac const