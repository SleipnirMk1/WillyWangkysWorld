#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "..\ADT\mesinkata\mesinkata.h"
#include "..\ADT\tree\tree.h"
#include "point.h"
#include "arraywahana.h"
#include "player.h"
#include "stackaction.h"
#include "wahana.h"
#include "ReadWrite.c"

// Membaca dari file seharusnya, klo ga ya buat tree sendiri
Tree generateWahanaUpgradeTree()
{
	Tree W;
	W = ReadWahana("wahana.txt");
	return W;
}

// Melayani Input jenis upgrade dengan melihat pohon upgrade
void CheckTreeUpgrade(Tree UpgradeTree, ArrayWahana T_built_wahana, ArrayWahana T_all_wahana, IdxType i_nearby, boolean * CanUpgrade, IdxType * TargetUpgrade)
{
	// Utk input tujuan upgrade
	Kalimat Q;

	// Fungsi mencari simpul yang sesuai dengan tipe wahana yg akan diupgrade
	Tree UpTarget = SearchTreeNode(UpgradeTree, Tipe(T_built_wahana, i_nearby));

	// Jika ditemukan simpul yang sesuai
	if (UpTarget != Nil)	
	{
		// Memastikan ada upgrade utk simpul
		if (Left(UpTarget) != Nil && Right(UpTarget) != Nil)
		{
			printf("%s\n", Info(Left(UpTarget)) );
			printf("%s\n", Info(Right(UpTarget)) );
			Q = GetKalimat();

			// Mencari informasi dari cabang upgrade wahana terpilih
			IdxType Target1 = Search1Wahana(T_all_wahana, Info(Left(UpTarget)) );
			IdxType Target2 = Search1Wahana(T_all_wahana, Info(Right(UpTarget)) );

			// Jika cabang kiri
			if (IsEQKalimat(Q, Nama(Elmt(T_all_wahana, Target1)) ) )
			{
				// Pengecekan resource, sama seperti build
				if (CanBuild(Elmt(T_all_wahana, Target1)) )
				{
					*CanUpgrade = true;
					*TargetUpgrade = Target1;
				}
				else
				{
					printf("Sumber daya tidak mencukupi\n");
				}
				
			}
			// Jika cabang kanan
			else if (IsEQKalimat(Q, Nama(Elmt(T_all_wahana, Target2)) ) )
			{
				// Pengecekan resource, sama seperti build
				if (CanBuild(Elmt(T_all_wahana, Target2)) )
				{
					*CanUpgrade = true;
					*TargetUpgrade = Target2;
				}
				else
				{
					printf("Sumber daya tidak mencukupi\n");
				}
			}
			// Pilihan cabang tidak tersedia
			else
			{
				printf("Tidak terdapat upgrade tersebut\n");
			}
		}
		// Tidak terdapat upgrade utk wahana
		else
		{
			printf("Wahana ini tidak memiliki upgrade\n");
		}
	}
	// Tidak ditemukan wahana dalam tree
	else
	{
		printf("Wahana tidak valid\n");
	}
}

// Melayani fungsi upgrade
void Upgrade (StackAction * S)
{
	// Cek ada wahana di sekitar player, fungsi yg sudah ada tidak masalah
	int IsAdaWahanaSekitar = IdxWahanaSekitar(P.Position);

	// Utk loop
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

	// Menyingkat nama variabel
	int Idx_sekitar = IsAdaWahanaSekitar;		
	ArrayWahana T_built = ListWahanaYangDimiliki;

	// Harus mengakses informasi wahana dari database yang mencangkup semua wahana
	// Berbeda dengan database wahana yang tersedia utk dibangun
	ArrayWahana T_all_wahana = generateListAllWahana();	

	// Mengakses pohon upgrade
	Tree UpTree;
	UpTree = generateWahanaUpgradeTree();

	while(IsUpgrading)
	{
		printf("Sedang meng-upgrade wahana %s\n", Nama(Elmt(T_built, Idx_sekitar)) );

		Kalimat K = GetKalimat();
		Kalimat K2 = K;
		Kata exitKata;
		DequeueKalimat(&K2, &exitKata);
		
		if(KataSama(exitKata, EXIT))
		{
			IsUpgrading = false;
			printf("Upgrade dibatalkan\n");
		}
		else
		{
			boolean CanUpgrade = false;
			// TargetUp adalah index wahana yang tujuan upgrade
			IdxType TargetUp;

			printf("Ingin upgrade menjadi apa?\n");
			CheckTreeUpgrade(UpTree, T_built, T_all_wahana, Idx_sekitar, &CanUpgrade, &TargetUp);

			if (CanUpgrade)
			{
				Action A;
				ActionName(A) = Nama(Elmt(T_all_wahana, TargetUp));
				SetKata(&ActionType(A), "upgrade");	
				ActionTime(A) = UPGRADETIME;
				ActionAmount(A) = 1;
				ActionPrice(A) = Price(Elmt(T_all_wahana, TargetUp));	// harga uang
				
				// lokasi wahana lama, bisa utk rujukan ke wahana lama
				ActionPosition(A) = Lokasi(Elmt(T_built, Idx_sekitar));	

				// Keperluan material
				Wood(ActionMaterialCost(A)) = Wood(MaterialCost(Elmt(T_all_wahana, TargetUp)));	// harga kayu
				Stone(ActionMaterialCost(A)) = Stone(MaterialCost(Elmt(T_all_wahana, TargetUp)));	// harga batu
				Iron(ActionMaterialCost(A)) = Iron(MaterialCost(ElmtT_all_wahana, TargetUp)));		// harga besi
				
				PushAction(S, A);	// Push ke stack

				P.Debt += Price(Elmt(T_all_wahana, TargetUp));

				printf("Perintah Upgrade ");
				PrintQueue(K);
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

void executeUpgrade(StackAction * S)
{
	// 1. Ambil list berkait histori upgrade wahana yg hendak diupgrade, simpan ke variabel
	// (sudah ditambahkan List Upgrade ke ADT wahana)
	//Idenya adalah pada saat build, List ini diisikan tipe wahana yang dibangun sebagai elemen pertama
	
	// 2. Ambil data lokasi dari wahana yang hendak diupgrade, simpan ke variabel

	// 3. Hapus wahana dari list wahana yang sudah dibangun

	// 4. Bangun wahana upgraded di lokasi yang sama (bisa pake build)

	// 5. Histori upgrade utk wahana yang baru dimasukkan list dari wahana lama, 

	// 6. Histori upgrade wahana baru ditambah tipe wahana baru sebagai elemen terakhir
}