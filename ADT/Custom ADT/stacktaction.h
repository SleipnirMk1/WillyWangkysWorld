/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "jam.h"
#include "point.h"

#define Nil -1
#define MaxElStack 10
/* Nil adalah stack dengan elemen kosong . */

// Tipe Aksi
#define BUILDTYPE 1
#define BUYTYPE 2
#define UPGRADETYPE 3

/* *** Definisi TYPE PLAYER DATA *** */
typedef struct {
    int TipeAksi;
	  JAM Waktu;
    int Uang;
    int Wood;
    int Stone;
    int Iron;
    POINT LokasiBuild;
} actiontype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  actiontype T[MaxElStack]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} StackAction;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxElStack-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
/* S merupakan Stackt, I merupakan Infotype Stackt */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define InfoTopTipe(S) (S).T[(S).TOP].TipeAksi
#define InfoTopWaktu(S) (S).T[(S).TOP].Waktu
#define InfoTopWood(S) (S).T[(S).TOP].Wood
#define InfoTopStone(S) (S).T[(S).TOP].Stone
#define InfoTopIron(S) (S).T[(S).TOP].Iron
#define InfoTopLokasi(S) (S).T[(S).TOP].LokasiBuild

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (StackAction *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (StackAction S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (StackAction S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (StackAction * S, actiontype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (StackAction * S, actiontype * X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
