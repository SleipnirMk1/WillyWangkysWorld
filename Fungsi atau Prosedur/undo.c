#include <stdio.h>
#include "mesinkata.h"

#define BUILDTIME 300

Kata BUILDTYPE;

void Undo (StackAction *S)
{
	Action A;
	Pop(S, &A);

	printf("Menghapus Perintah ");
	PrintKata(ActionType(A));
	printf(" ");
	PrintKata(ActionName(A));
	printf(" dari Stack!!\n");
}