#include <stdio.h>
#include "mesinkata.h"

#define BUILDTIME 300

Kata BUILDTYPE;

void RandomAntrian(Antrian *A, Wahana W)
{
	for (int i = 0; i < MaxAntrian; ++i)
	{
		idxWahana = random(0, NbWahana(W));

		Antri Q;
		AntriName(Q) = W[idxWahana].Name;
		AntriPrio(Q) = 5;

		Enqueue(A, Q);
	}
}