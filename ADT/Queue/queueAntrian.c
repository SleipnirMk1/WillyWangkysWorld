/*  NIM                 : 13519159                      */
/*  Nama                : Benidictus Galih Mahar Putra  */
/*  Tanggal             : 08 Oktober 2020               */
/*  Topik praktikum     : ADT Queue                     */
/*  Deskripsi           : Membuat implementasi atau source code dari fungsi header queue.h */

/* File : prioqueue.c */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#include <stdlib.h>
#include <stdio.h>
#include "queueAntrian.h"
#include "boolean.h"
#include "..\mesinkata\mesinkata.h"

// #define Nil -1
// /* Konstanta untuk mendefinisikan address tak terdefinisi */

// /* Definisi elemen dan address */
// typedef struct {
//     int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
//     char info;  /* elemen karakter */
// } infotype;
// typedef int address;   /* indeks tabel */
// /* Contoh deklarasi variabel bertype PrioQueueChar : */
// /* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct {
//     infotype * T;   /* tabel penyimpan elemen */
//     address HEAD;   alamat penghapusan 
//     address TAIL;  /* alamat penambahan */
//     int MaxEl;     /* Max elemen queue */
// } PrioQueueChar;
// /* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */

// /* ********* AKSES (Selektor) ********* */
// /* Jika e adalah infotype dan Q adalah PrioQueueChar, maka akses elemen : */
// #define Prio(e)     (e).prio
// #define Info(e)     (e).info
// #define Head(Q)     (Q).HEAD
// #define Tail(Q)     (Q).TAIL
// #define InfoHead(Q) (Q).T[(Q).HEAD]
// #define InfoTail(Q) (Q).T[(Q).TAIL]
// #define MaxEl(Q)    (Q).MaxEl
// #define Elmt(Q,i)   (Q).T[(i)]


/* ********* Prototype ********* */
boolean IsEmptyQueueAntrian (QueueAntrian Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q) == Nil || Tail(Q) == Nil);
}


boolean IsFullQueueAntrian (QueueAntrian Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	if (IsEmptyQueueAntrian(Q))
		return false;
	else
		if (Head(Q) == 0 && Tail(Q) == MaxEl(Q)-1)
			return true;
		else if (Tail(Q) == Head(Q)-1)
			return true;
		else
			return false;
}

int NBElmtQueueAntrian (QueueAntrian Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if (IsEmptyQueueAntrian(Q))
		return 0;
	else
	{
		if (Head(Q) <= Tail(Q))
			return (Tail(Q) - Head(Q) + 1);
		else
			return (MaxEl(Q)-1 - Head(Q) + 1) + (Tail(Q) - 0 + 1);
	}
}



/* *** Kreator *** */
void MakeEmptyQueueAntrian (QueueAntrian * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype*) malloc (Max*sizeof(infotype));

	if ((*Q).T != NULL)
	{
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
 	}
 	else
 	{
 		MaxEl(*Q) = 0;
 	}
}



/* *** Destruktor *** */
void DeAlokasiQueueAntrian(QueueAntrian * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	MaxEl(*Q) = 0;
	free((*Q).T);
}



/* *** Primitif Add/Delete *** */
void EnqueueAntrian (QueueAntrian * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
	if (IsEmptyQueueAntrian(*Q))
	{
		Head(*Q) = 0;
		Tail(*Q) = 0;

		InfoTail(*Q) = X;
	}
	else
	{
		if (Head(*Q) <= Tail(*Q))
		{
			boolean found = false;
			int i = Head(*Q);
			while(i <= Tail(*Q) && !found)
			{
				if (PrioAntrian(Elmt(*Q, i)) > PrioAntrian(X))
				{
					found = true;
				}
				else
				{
					i++;
				}
			}

			if (!found)
			{
				Tail(*Q)++;
				InfoTail(*Q) = X;
			}
			else
			{
				for (int j = Tail(*Q); j >= i; j--)
				{
					if (j == MaxEl(*Q)-1)
					{
						Elmt(*Q, 0) = Elmt(*Q, j);
					}
					else
					{
						Elmt(*Q, j+1) = Elmt(*Q, j);
					}
				}

				if (Tail(*Q) == MaxEl(*Q)-1)
					Tail(*Q) = 0;
				else
					Tail(*Q)++;

				Elmt(*Q, i) = X;
			}
		}
		else
		{
			boolean found = false;
			int i = Head(*Q);
			while(i <= MaxEl(*Q)-1 && !found)
			{
				if (PrioAntrian(Elmt(*Q, i)) > PrioAntrian(X))
				{
					found = true;
				}
				else
				{
					i++;
				}
			}

			if (!found)
			{
				i = 0;
				while(i <= Tail(*Q) && !found)
				{
					if (PrioAntrian(Elmt(*Q, i)) > PrioAntrian(X))
					{
						found = true;
					}
					else
					{
						i++;
					}
				}
			}


			if (!found)
			{
				Tail(*Q)++;
				InfoTail(*Q) = X;
			}
			else
			{	
				if (i <= Tail(*Q))
				{
					for (int j = Tail(*Q); j >= i; j--)
					{
						Elmt(*Q, j+1) = Elmt(*Q, j);
					}

					Tail(*Q)++;
					Elmt(*Q, i) = X;
				}
				else
				{
					for (int j = Head(*Q); j < i; j++)
					{
						Elmt(*Q, j-1) = Elmt(*Q, j);
					}

					Head(*Q)--;
					Elmt(*Q, i-1) = X;
				}
			}
		}
	}
}


void DequeueAntrian (QueueAntrian * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	*X = InfoHead(*Q);

	if (Tail(*Q) == Head(*Q))
	{
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else
	{
		if (Head(*Q) == MaxEl(*Q)-1)
			Head(*Q) = 0;
		else
			Head(*Q)++;
	}
}



/* Operasi Tambahan */
void PrintQueueAntrian (QueueAntrian Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	if (IsEmptyQueueAntrian(Q))
	{
		printf("[]");
	}
	else if (Head(Q) <= Tail(Q))
	{
		printf("[");
		for (int i = Head(Q); i <= Tail(Q); i++)
		{
			PrintKalimat(InfoAntrian(Elmt(Q, i)));
			
			if (i != Tail(Q))
				printf(",");
		}
		printf("]");
	}
	else
	{
		printf("[");
		for (int i = Head(Q); i <= MaxEl(Q)-1; i++)
		{
			PrintKalimat(InfoAntrian(Elmt(Q, i)));
			printf(",");
		}

		for (int i = 0; i <= Tail(Q); i++)
		{
			PrintKalimat(InfoAntrian(Elmt(Q, i)));

			if (i != Tail(Q))
				printf(",");
		}
		printf("]");
	}
}