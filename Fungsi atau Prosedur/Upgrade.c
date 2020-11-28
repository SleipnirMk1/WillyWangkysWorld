#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../tree/tree.h"
#include "../point/point.h"
#include "../custom_adt/listlinierwahana.h"
#include "../custom_adt/player.h"
#include "../custom_adt/stackaction.h"
#include "../custom_adt/wahana.h"
#include "ReadWrite.c"

// Memperoleh wahana yang ada di sekitar pemain
ListWahana GetNearbyWahana (POINT posisi_player, ListWahana list_of_built_wahana)
{
	ListWahana Lout;
	CreateEmptyW(&Lout);

	if (IsEmpty(list_of_built_wahana)){
        return Nil;
    }
    else
	{
		float X, Y;
		int A;
		address Elmt = First(list_of_built_wahana);
        while (Elmt != Nil)
		{
			X = Absis(Lokasi(Info(Elmt)));
			Y = Ordinat(Lokasi(Info(Elmt)));
			A = Area(Lokasi(Info(Elmt)));

			if (Area(posisi_player) == A)
			{
				if ((X + 1) == Absis(posisi_player) && Y == Ordinat(posisi_player))
				{
					InsVLast(&Lout, Info(Elmt));
				}
				else if ((X - 1) == Absis(posisi_player) && Y == Ordinat(posisi_player))
				{
					InsVLast(&Lout, Info(Elmt));
				}
				else if (X  == Absis(posisi_player) && (Y + 1) == Ordinat(posisi_player))
				{
					InsVLast(&Lout, Info(Elmt));
				}
				else if (X  == Absis(posisi_player) && (Y - 1) == Ordinat(posisi_player))
				{
					InsVLast(&Lout, Info(Elmt));
				}
			}

			Elmt = Next(Elmt);
		}
    }

	return Lout;
}

void Upgrade (StackAction *S, WAHANA *W, Player player)
{
	ListWahana L;
	CreateEmptyW(&L);
	
	L = ReadWahanaInfo("wahanainfo.txt");

	Tree W1, W2, W3;
	ReadWahana("wahana.txt", &W1, &W2, &W3);

	boolean upgrade = true;

	while(upgrade)
	{
		ListWahana arr = GetNearbyWahana(Position(player));	// Masukkan data posisi pemain

		if (IsEmpty(arr))
		{
			printf("Tidak ada wahana yang bisa di upgrade di sekitar\n");
			upgrade = false;
		}

		printf("Ingin upgrade wahana apa?\n");

        int i;
		for (i = 0; i < NbElmt(arr); ++i)
        {
            printf("%s\n", Elmt(arr, i));     // Print nama wahana yang tersedia
        }

		QueueKata K = GetQueueKata();
		
		if(IsEQ(K, EXIT))
		{
			upgrade = false;
			printf("Upgrade dibatalkan\n");
		}
		else
		{
			boolean inReach = false;
			for (i = 0; i < NbElmt(arr); ++i)
			{
				if (IsEQ(K, Elmt(arr, i)))
                {
                    inReach = true;
                }
			}

			if (!inReach)
			{
				printf("Wahana yang dipilih tidak dalam jangkauan\n");
			}
			else
			{
				boolean CanUpgrade = false;
				printf("Ingin upgrade menjadi apa?\n");
				QueueKata Q;
				address P;
				Material MOwn, MCost;

				int Durasi;
				int Uang, Wood, Stone, Iron;

				// Bagian bawahnya nantinya mau dibuat fungsi lagi biar lebih rapi

				if (IsEQ(K, Info(W1)))
				{
					printf("%s\n", Left(W1));
					printf("%s\n", Right(W1));
					Q = GetQueueKata();

					if (IsEQ(Q, Left(W1)))
					{
						P = Search(L, Left(W1));	// Mungkin fungsi search nya perlu di ubah
						MCost = MaterialCost(Info(P));
						MOwn = Material(player);
						if (Money(player) >= Price(Info(P)) && Wood(MOwn) >= Wood(MCost) && Stone(MOwn) >= Stone(Info(MCost)) && Iron(MOwn) >= Iron(Info(MCost)) && Mamank(MOwn) >= Mamank(MCost))	// Cek resource
						{
							boolean CanUpgrade = true;
						}
					}
					else if (IsEQ(Q, Right(W1)))
					{
						P = Search(L, Right(W1));	// Mungkin fungsi search nya perlu di ubah
						MCost = MaterialCost(Info(P));
						MOwn = Material(player);
						if (Money(player) >= Price(Info(P)) && Wood(MOwn) >= Wood(MCost) && Stone(MOwn) >= Stone(Info(MCost)) && Iron(MOwn) >= Iron(Info(MCost)) && Mamank(MOwn) >= Mamank(MCost))	// Cek resource
						{
							boolean CanUpgrade = true;
						}
					}
				}
				else if (IsEQ(K, Info(W2)))
				{
					printf("%s\n", Left(W2));
					printf("%s\n", Right(W2));
					Q = GetQueueKata();

					if (IsEQ(Q, Left(W2)))
					{
						P = Search(L, Left(W2));	// Mungkin fungsi search nya perlu di ubah
						MCost = MaterialCost(Info(P));
						MOwn = Material(player);
						if (Money(player) >= Price(Info(P)) && Wood(MOwn) >= Wood(MCost) && Stone(MOwn) >= Stone(Info(MCost)) && Iron(MOwn) >= Iron(Info(MCost)) && Mamank(MOwn) >= Mamank(MCost))	// Cek resource
						{
							boolean CanUpgrade = true;
						}
					}
					else if (IsEQ(Q, Right(W2)))
					{
						P = Search(L, Right(W2));	// Mungkin fungsi search nya perlu di ubah
						MCost = MaterialCost(Info(P));
						MOwn = Material(player);
						if (Money(player) >= Price(Info(P)) && Wood(MOwn) >= Wood(MCost) && Stone(MOwn) >= Stone(Info(MCost)) && Iron(MOwn) >= Iron(Info(MCost)) && Mamank(MOwn) >= Mamank(MCost))	// Cek resource
						{
							boolean CanUpgrade = true;
						}
					}
				}
				else if (IsEQ(K, Info(W3)))
				{
					printf("%s\n", Left(W3));
					printf("%s\n", Right(W3));
					Q = GetQueueKata();

					if (IsEQ(Q, Left(W3)))
					{
						P = Search(L, Left(W3));	// Mungkin fungsi search nya perlu di ubah
						MCost = MaterialCost(Info(P));
						MOwn = Material(player);
						if (Money(player) >= Price(Info(P)) && Wood(MOwn) >= Wood(MCost) && Stone(MOwn) >= Stone(Info(MCost)) && Iron(MOwn) >= Iron(Info(MCost)) && Mamank(MOwn) >= Mamank(MCost))	// Cek resource
						{
							boolean CanUpgrade = true;
						}
					}
					else if (IsEQ(Q, Right(W3)))
					{
						P = Search(L, Right(W3));	// Mungkin fungsi search nya perlu di ubah
						MCost = MaterialCost(Info(P));
						MOwn = Material(player);
						if (Money(player) >= Price(Info(P)) && Wood(MOwn) >= Wood(MCost) && Stone(MOwn) >= Stone(Info(MCost)) && Iron(MOwn) >= Iron(Info(MCost)) && Mamank(MOwn) >= Mamank(MCost))	// Cek resource
						{
							boolean CanUpgrade = true;
						}
					}
				}
				else
				{
					printf("Tidak ada upgrade untuk wahana ini\n");
				}

				Durasi = Durasi(Info(P));
				Uang = Price(Info(P));
				Wood = Wood(MCost);
				Stone = Stone(MCost);
				Iron = Iron(MCost);

				if (CanUpgrade)
				{
					Action A;
					ActionName(A) = "Upgrade";
					ActionType(A) = UPGRADETYPE;
					ActionTime(A) = Durasi;
					ActionAmount(A) = 1;
					ActionPrice(A) = Uang;
					ActionPosition(A) = Lokasi(Info(P));
					Wood(ActionMaterialCost(A)) = Wood;
					Stone(ActionMaterialCost(A)) = Stone;
					Iron(ActionMaterialCost(A)) = Iron;

					Push(S, A);

					printf("Perintah Upgrade ");
					PrintQueue(K);
					printf("Menjadi ");
					PrintQueue(Q);
					printf(" dimasukkan ke dalam Stack\n");

					upgrade = false;
				}
				else
				{
					printf("Tidak dapat melakukan upgrade ");
					PrintQueue(K);
					printf("\n");
				}
			}
		}
	}
}