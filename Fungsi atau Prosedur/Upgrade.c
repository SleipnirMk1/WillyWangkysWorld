#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"
#include "tree.h"
#include "point.h"
#include "arraywahana.h"
#include "player.h"
#include "stackaction.h"
#include "wahana.h"
#include "ReadWrite.c"

// Mengecek material dan uang
boolean IsMaterialEnough(Material MOwn, Material MCost, ArrayWahana L, IdxType P, Player player)
{
	return(Money(player) >= Price(Elmt(L,P)) && Wood(MOwn) >= Wood(MCost) && Stone(MOwn) >= Stone(MCost) && Iron(MOwn) >= Iron(MCost) && Mamank(MOwn) >= Mamank(MCost))
}

// Mengecek apakah dapat upgrade dan menyatakan bisa dengan CanUpgrade
void CheckCanUpgrade(Tree W1, ArrayWahana L, Player player, boolean * CanUpgrade, IdxType * Cost)
{
	IdxType P = Search1Wahana(L, W1);
	Material MCost = MaterialCost(Elmt(L, P));
	Material MOwn = Material(player);
	if (IsMaterialEnough(MOwn, MCost, L, P, player))	// Cek resource
	{
		*CanUpgrade = true;
		*Cost = P;
	}
}

// Melayani Input jenis upgrade dengan melihat pohon upgrade
void CheckTreeUpgrade(Tree W1, QueueKata K, ArrayWahana L, Player player, boolean * CanUpgrade, IdxType * Cost)
{
	QueueKata Q;

	if (IsEQKalimat(K, Info(W1)))
	{
		if (Left(W1) != Nil && Right(W1) != Nil)
		{
			printf("%s\n", Left(W1));
			printf("%s\n", Right(W1));
			Q = GetQueueKata();

			if (IsEQWahana(Q, Left(W1)))
			{
				CheckCanUpgrade(Left(W1), L, player, CanUpgrade, Cost);
			}
			else if (IsEQWahana(Q, Right(W1)))
			{
				CheckCanUpgrade(Right(W1), L, player, CanUpgrade, Cost);
			}
		}
	}
}

// Memperoleh wahana yang ada di sekitar pemain
ArrayWahana GetNearbyWahana (POINT posisi_player, ArrayWahana array_of_built_wahana)
{
	ArrayWahana Lout;
	MakeEmptyWahana(&Lout);

    if (!IsEmptyWahana(array_of_built_wahana))
	{
		float X, Y;
		int i, A;
        for (i = GetFirstIdxWahana(array_of_built_wahana); i <= GetLastIdxWahana(array_of_built_wahana); ++i)
		{
			X = Absis(Lokasi(Elmt(array_of_built_wahana, i)));
			Y = Ordinat(Lokasi(Elmt(array_of_built_wahana, i)));
			A = Area(Lokasi(Elmt(array_of_built_wahana, i)));

			if (Area(posisi_player) == A)
			{
				if ((X + 1) == Absis(posisi_player) && Y == Ordinat(posisi_player))
				{
					AddAsLastElWahana(&Lout, Elmt(array_of_built_wahana, i))
				}
				else if ((X - 1) == Absis(posisi_player) && Y == Ordinat(posisi_player))
				{
					AddAsLastElWahana(&Lout, Elmt(array_of_built_wahana, i))
				}
				else if (X  == Absis(posisi_player) && (Y + 1) == Ordinat(posisi_player))
				{
					AddAsLastElWahana(&Lout, Elmt(array_of_built_wahana, i))
				}
				else if (X  == Absis(posisi_player) && (Y - 1) == Ordinat(posisi_player))
				{
					AddAsLastElWahana(&Lout, Elmt(array_of_built_wahana, i))
				}
			}
		}
    }

	return Lout;
}

// Melayani fungsi upgrade
void Upgrade (StackAction *S, WAHANA *W, Player player)
{
	ArrayWahana L;
	MakeEmptyWahana(&L);
	
	L = ReadWahanaInfo("wahanainfo.txt");

	Tree W1, W2, W3;
	ReadWahana("wahana.txt", &W1, &W2, &W3);

	boolean upgrade = true;

	while(upgrade)
	{
		ArrayWahana arr = GetNearbyWahana(Position(player), array_of_built_wahana);	// Masukkan data posisi pemain

		if (IsEmptyWahana(arr))
		{
			printf("Tidak ada wahana yang bisa di upgrade di sekitar\n");
			upgrade = false;
		}

		printf("Ingin upgrade wahana apa?\n");

        int i;
		for (i = 0; i < NbElmtWahana(arr); ++i)
        {
            printf("%s\n", Nama(Elmt(arr, i)));     // Print nama wahana yang tersedia
        }

		QueueKata K = GetQueueKata();
		
		if(IsEQKalimat(K, EXIT))
		{
			upgrade = false;
			printf("Upgrade dibatalkan\n");
		}
		else
		{
			boolean inReach = false;
			for (i = 0; i < NbElmtWahana(arr); ++i)
			{
				if (IsEQKalimat(K, Nama(Elmt(arr, i))))
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

				IdxType Cost;
				
				CheckTreeUpgrade(W1, K, L, player, &CanUpgrade, &Cost);

				CheckTreeUpgrade(W2, K, L, player, &CanUpgrade, &Cost);

				CheckTreeUpgrade(W3, K, L, player, &CanUpgrade, &Cost);

				

				if (CanUpgrade)
				{
					Durasi = Durasi(Info(P));
					Uang = Price(Info(P));
					Wood = Wood(MCost);
					Stone = Stone(MCost);
					Iron = Iron(MCost);

					Action A;
					ActionName(A) = "Upgrade";
					ActionType(A) = UPGRADETYPE;
					ActionTime(A) = Durasi(Elmt(L,Cost));
					ActionAmount(A) = 1;
					ActionPrice(A) = Price(Elmt(L,Cost));
					ActionPosition(A) = Lokasi(Elmt(L,Cost));
					Wood(ActionMaterialCost(A)) = Wood(MaterialCost(Elmt(L,Cost)));
					Stone(ActionMaterialCost(A)) = Stone(MaterialCost(Elmt(L,Cost)));
					Iron(ActionMaterialCost(A)) = Iron(MaterialCost(Elmt(L,Cost)));

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