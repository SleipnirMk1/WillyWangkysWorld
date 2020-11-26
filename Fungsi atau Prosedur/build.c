#include <stdio.h>
#include "mesinkata.h"

#define BUILDTIME 300

Kata BUILDTYPE;

void Build (Stack*S, Wahana *W, ListWahana W1)
{
	boolean build = true;
	while(build)
	{
		printf("Ingin Membangun apa?\n");
		PrintListWahana();
		QueueKata K = GetQueue();
		
		if(IsEQ(K, EXIT))
		{
			build = false;
			printf("Pembangunan dibatalkan!!\n");
		}
		else
		{
			boolean available = false;
			int i = 0;
			while(i < NbWahana(W1) && !available)
			{
				if (IsEQ(K, W1[i]))
					available = true;
				else
					i++;
			}

			if (!available)
			{
				printf("Wahana yang dipilih tidak tersedia!!\n");
			}
			else
			{

				if (CanBuild)
				{
					Action A;
					ActionName(A) = K;
					ActioneType(A) = BUILDTYPE;
					ActionTime(A) = BUILDTIME;
					ActionAmount(A) = 1;
					ActionPos(A) = Player.Pos;

					Push(S, A);

					printf("Perintah Build ");
					PrintQueue(K);
					printf(" dimasukkan ke dalam Stack\n");

					build = false;
				}
				else
				{
					printf("Tidak dapat melakukan pembangunan ");
					PrintQueue(K);
					printf("\n");
				}
			}
		}
	}
	
}