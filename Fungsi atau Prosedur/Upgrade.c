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

// Membaca dari file seharusnya, klo ga ya buat tree sendiri
void generateWahanaUpgradeTree(Tree * W1, Tree * W2, Tree * W3)
{
	ReadWahana("wahana.txt", &W1, &W2, &W3);
}

// Melayani Input jenis upgrade dengan melihat pohon upgrade
void CheckTreeUpgrade(Tree W, IdxType i, boolean * CanUpgrade, IdxType * Cost)
{
	Kalimat Q;
	ArrayWahana T = generateListWahanaTujuanUpgrade();		// Perlu beda dari list wahana yg bisa dibangun

	if (KalimatSama(Nama(Elmt(T,i)), Info(W)))	//Nama wahana di pohon sama dengan nama wahana dekat pemain
	{
		if (Left(W) != Nil && Right(W) != Nil)	// Memastikan ada upgrade
		{
			printf("%s\n", Info(Left(W)) );
			printf("%s\n", Info(Right(W)) );
			Q = GetKalimat();

			if (KalimatSama(Q, Info(Left(W)) ) )
			{
				IdxType j = Search1Wahana(T, Info(Left(W)) );	// Cari wahana dari list of wahana
				if (CanBuild(Elmt(T,j)) )
				{
					*CanUpgrade = true;
					*Cost = j;
				}
			}
			else if (KalimatSama(Q, Info(Right(W)) ) )
			{
				IdxType j = Search1Wahana(T, Info(Right(W)) );
				if (CanBuild(Elmt(T,j)) )
				{
					*CanUpgrade = true;
					*Cost = j;
				}
			}
		}
	}
}

// Melayani fungsi upgrade
void Upgrade ()
{
	int IsAdaWahanaSekitar = IdxWahanaSekitar(P.Position);
	boolean IsUpgrading;

	if (IsAdaWahanaSekitar = -1)
	{
		printf("Tidak ada wahana yang tersedia!!\n");
		IsUpgrading = false;
	}
	else
	{
		IsUpgrading = true;
	}

	int i = IsAdaWahanaSekitar;
	ArrayWahana T = ListWahanaYangDimiliki;

	Tree W1, W2, W3;
	generateWahanaUpgradeTree(&W1, &W2, &W3);	// Pohon upgrade W1, W2, W3

	while(IsUpgrading)
	{
		printf("Sedang meng-upgrade wahana %s\n", Nama(Elmt(T,i)));

		Kalimat K = GetKalimat();
		Kalimat K2 = K;
		Kata exitKata;
		DequeueKalimat(&K2, &exitKata);
		
		if(KataSama(exitKata, EXIT))
		{
			upgrade = false;
			printf("Upgrade dibatalkan\n");
		}
		else
		{
			boolean CanUpgrade = false;
			IdxType Cost;	// Cost adalah index wahana yang tujuan upgrade
			printf("Ingin upgrade menjadi apa?\n");
				
			CheckTreeUpgrade(W1, i, player, &CanUpgrade, &Cost);
			CheckTreeUpgrade(W2, i, player, &CanUpgrade, &Cost);
			CheckTreeUpgrade(W3, i, player, &CanUpgrade, &Cost);

			if (CanUpgrade)
			{
				Action A;
				ActionName(A) = Nama(Elmt(T, Cost));	// nama aksi
				SetKata(&ActionType(A), "upgrade");		// tipe aksi
				ActionTime(A) = Durasi(Elmt(T,Cost));	// lama upgrade
				ActionAmount(A) = 1
				ActionPrice(A) = Price(Elmt(L,Cost));	// harga uang
				ActionPosition(A) = Lokasi(Elmt(L,i));		// lokasi wahana lama
				Wood(ActionMaterialCost(A)) = Wood(MaterialCost(Elmt(L,Cost)));	// harga kayu
				Stone(ActionMaterialCost(A)) = Stone(MaterialCost(Elmt(L,Cost)));	// harga batu
				Iron(ActionMaterialCost(A)) = Iron(MaterialCost(Elmt(L,Cost)));		// harga besi
				
				PushAction(&S, A);

				P.Debt += Price(Elmt(L,Cost));

				printf("Perintah Upgrade ");
				PrintQueue(K);
				printf("Menjadi ");
				PrintQueue(Q);
				printf(" dimasukkan ke dalam Stack\n");

				IsUpgrading = false;
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