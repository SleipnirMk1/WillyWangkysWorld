#include <stdio.h>
#include <stdlib.h>
#include "arraywahana.h"
#include "boolean.h"
#include "mesinkata.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyWahana (ArrayWahana * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxWahana-IdxMinWahana+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	(*T).TI[IdxMaxWahana-IdxMinWahana+1];

	int i;
	for(i=IdxMinWahana; i<=IdxMaxWahana; i++)
	{
		Tipe(Elmt(*T, i)) = ValUndef;
	}
}



/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtWahana (ArrayWahana T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	int count = 0;

	while(Tipe(Elmt(T, count)) != ValUndef && count <= IdxMaxWahana)
	{
		count++;
	}

	return count;
}


/* *** Daya tampung container *** */
int MaxNbElWahana (ArrayWahana T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMaxWahana - IdxMinWahana + 1;
}



/* *** Selektor INDEKS *** */
IdxType GetFirstIdxWahana (ArrayWahana T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMinWahana;
}


IdxType GetLastIdxWahana (ArrayWahana T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return NbElmtWahana(T) - 1;
}



/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidWahana (ArrayWahana T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return i >= IdxMinWahana && i <= IdxMaxWahana;
}


boolean IsIdxEffWahana (ArrayWahana T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	if (NbElmtWahana(T) == 0)
		return false;
	else
	{
		return i >= GetFirstIdxWahana(T) && i <= GetLastIdxWahana(T);
	}
}



/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyWahana (ArrayWahana T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return NbElmtWahana(T) == 0;
}



/* *** Test tabel penuh *** */
boolean IsFullWahana (ArrayWahana T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return NbElmtWahana(T) == MaxNbElWahana(T);
}



/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

void TulisIsiTabWahana (ArrayWahana T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	if (IsEmptyWahana(T))
	{
		printf("[]");
	}
	else
	{
		int n = NbElmtWahana(T);
		int i;

		printf("[");
		for(i = IdxMinWahana; i < n; i++)
		{
			printf("%s", Nama(Elmt(T,i)));

			if(i != GetLastIdxWahana(T))
				printf(",");
		}
		printf("]");
	}
}



/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQWahana (ArrayWahana T1, ArrayWahana T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	if (NbElmtWahana(T1) != NbElmtWahana(T2))
	{
		return false;
	}
	else
	{
		boolean Eq = true;

		int n = NbElmtWahana(T1);
		int i = IdxMinWahana;

		while(i < n && Eq)
		{
			if (!IsEQKalimat(Nama(Elmt(T1, i)), Nama(Elmt(T2, i))))
				Eq = false;

			i++;
		}

		return Eq;
	}
}



/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1Wahana (ArrayWahana T, Kalimat X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	if (IsEmptyWahana(T))
	{
		return IdxUndef;
	}
	else
	{
		boolean found = false;

		int n = NbElmtWahana(T);
		int i = IdxMinWahana;

		while (!found && i < n)
		{
			if (!IsEQKalimat(Nama(Elmt(T, i)), X))
				found = true;
			else
				i++;
		}

		if (found)
			return i;
		else
			return IdxUndef;
	}
}


boolean SearchBWahana (ArrayWahana T, Kalimat X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
	boolean found = false;

	int n = NbElmtWahana(T);
	int i = IdxMinWahana;

	while (!found && i < n)
	{
		if (!IsEQKalimat(Nama(Elmt(T, i)), X))
			found = true;

		i++;
	}

	return found;
}




/* ********** OPERASI LAIN ********** */

int CountXWahana (ArrayWahana T, wahanatype X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	int count = 0;

	int n = NbElmtWahana(T);
	int i;

	for (i = IdxMinWahana; i < n; i++)
	{
		if (!IsEQKalimat(Nama(Elmt(T, i)), Nama(X)))
			count++;
	}

	return count;
}




/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastElWahana (ArrayWahana * T, wahanatype X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	int n = NbElmtWahana(*T);

	Elmt(*T, n) = X;
}



/* ********** MENGHAPUS ELEMEN ********** */
void DelLastElWahana (ArrayWahana * T, wahanatype * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	int last = GetLastIdxWahana(*T);

	*X = Elmt(*T, last);

	Tipe(Elmt(*T, last)) = ValUndef;
}