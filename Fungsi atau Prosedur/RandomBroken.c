#include <stdio.h>
#include "mesinkata.h"

#define BUILDTIME 300

Kata BUILDTYPE;

void RandomBroken(int idxWahana, Wahana *W)
{
	int broke = random(0, 5);

	if (broke >=4 && broke <= 5)
	{
		(*W)[idxWahana].Status = BROKESTATUS;
		printf("Wahana ");
		PrintKata((*W)[idxWahana].Name)
		printf(" Telah Rusak!!");
	}
}