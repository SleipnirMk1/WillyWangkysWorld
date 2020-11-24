#include <stdio.h>
#include <stdlib.h>
#include "arraypos.h"
#include "boolean.h"



/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	(*T).TI[IdxMax-IdxMin+1];

	int i;
	for(i=IdxMin; i<=IdxMax; i++)
	{
		Elmt(*T, i) = ValUndef;
	}
}



/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	int count = 0;

	while(Elmt(T, count) != ValUndef && count <= IdxMax)
	{
		count++;
	}

	return count;
}


/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMax - IdxMin + 1;
}



/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}


IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return NbElmt(T) - 1;
}



/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return i >= IdxMin && i <= IdxMax;
}


boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	if (NbElmt(T) == 0)
		return false;
	else
	{
		return i >= GetFirstIdx(T) && i <= GetLastIdx(T);
	}
}



/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return NbElmt(T) == 0;
}



/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return NbElmt(T) == MaxNbEl(T);
}



/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	MakeEmpty(T);

	int N;
	scanf("%d", &N);

	while(N < 0 || N >= MaxNbEl(*T))
	{
		scanf("%d", &N);
	}

	int i;
	for(i = IdxMin; i<N; i++)
	{
		ElType val;
		scanf("%d", &val);

		Elmt(*T, i) = val;
	}
	
}


void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	if (IsEmpty(T))
	{
		printf("[]");
	}
	else
	{
		int n = NbElmt(T);
		int i;

		printf("[");
		for(i = IdxMin; i < n; i++)
		{
			printf("%d", Elmt(T,i));

			if(i != GetLastIdx(T))
				printf(",");
		}
		printf("]");
	}
}



/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	TabInt T;
	MakeEmpty(&T);

	int sign;
	if(plus)
		sign = 1;
	else
		sign = -1;

	int n = NbElmt(T1);
	int i;

	for(i=IdxMin; i < n; i++)
	{
		Elmt(T, i) = Elmt(T1, i) + (sign * Elmt(T2, i));
	}

	return T;
}



/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	if (NbElmt(T1) != NbElmt(T2))
	{
		return false;
	}
	else
	{
		boolean Eq = true;

		int n = NbElmt(T1);
		int i = IdxMin;

		while(i < n && Eq)
		{
			if (Elmt(T1, i) != Elmt(T2, i))
				Eq = false;

			i++;
		}

		return Eq;
	}
}



/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	if (IsEmpty(T))
	{
		return IdxUndef;
	}
	else
	{
		boolean found = false;

		int n = NbElmt(T);
		int i = IdxMin;

		while (!found && i < n)
		{
			if (Elmt(T, i) == X)
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


boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
	boolean found = false;

	int n = NbElmt(T);
	int i = IdxMin;

	while (!found && i < n)
	{
		if (Elmt(T, i) == X)
			found = true;

		i++;
	}

	return found;
}



/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	int n = NbElmt(T);
	int i = IdxMin;

	*Max = Elmt(T, i);
	*Min = Elmt(T, i);

	for (i = 1; i < n; i++)
	{
		if (Elmt(T, i) > (*Max))
			*Max = Elmt(T, i);

		if (Elmt(T, i) < (*Min))
			*Min = Elmt(T, i);
	}
}



/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	ElType sum = 0;

	int n = NbElmt(T);
	int i;

	for (i=IdxMin; i < n; i++)
	{
		sum += Elmt(T, i);
	}

	return sum;
}


int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	int count = 0;

	int n = NbElmt(T);
	int i;

	for (i = IdxMin; i < n; i++)
	{
		if (Elmt(T, i) == X)
			count++;
	}

	return count;
}


boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
	boolean even = true;

	int n = NbElmt(T);
	int i = IdxMin;

	while(i < n && even)
	{
		if (Elmt(T, i) % 2 != 0)
			even = false;

		i++;
	}

	return even;
}



/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	if (asc)
	{
		int n = NbElmt(*T);
		int i,j;

		for(i = IdxMin; i < n-1; i++)
		{
			int minIdx = i;

			for (j = i+1; j < n; j++)
			{
				if (Elmt(*T, j) < Elmt(*T, minIdx))
					minIdx = j;
			}

			ElType tmp = Elmt(*T, i);
			Elmt(*T, i) = Elmt(*T, minIdx);
			Elmt(*T, minIdx) = tmp;
		}
	}
	else
	{
		int n = NbElmt(*T);
		int i,j;

		for(i = IdxMin; i < n-1; i++)
		{
			int maxIdx = i;

			for (j = i+1; j < n; j++)
			{
				if (Elmt(*T, j) > Elmt(*T, maxIdx))
					maxIdx = j;
			}

			ElType tmp = Elmt(*T, i);
			Elmt(*T, i) = Elmt(*T, maxIdx);
			Elmt(*T, maxIdx) = tmp;
		}
	}
}



/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	int n = NbElmt(*T);

	Elmt(*T, n) = X;
}



/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	int last = GetLastIdx(*T);

	*X = Elmt(*T, last);

	Elmt(*T, last) = ValUndef;
}