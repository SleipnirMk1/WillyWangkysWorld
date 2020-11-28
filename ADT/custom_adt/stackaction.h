/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
// #include "/jam.h"
#include "../point/point.h"
#include "../mesinkata/mesinkata.h"

#define Nil -1
#define MaxElStack 10
/* Nil adalah stack dengan elemen kosong . */

// Tipe Aksi
#define BUILDTYPE 1
#define BUYTYPE 2
#define UPGRADETYPE 3

/* *** Definisi TYPE PLAYER DATA *** */
typedef struct {
    Kalimat Name;
    Kata Type;
    int Time;
    int Amount;
    POINT Position;
} Action;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  Action T[MaxElStack]; /* tabel penyimpan elemen */
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
#define InfoTopName(S) (S).T[(S).TOP].Name
#define InfoTopTipe(S) (S).T[(S).TOP].Type
#define InfoTopWaktu(S) (S).T[(S).TOP].Time
#define InfoTopAmount(S) (S).T[(S).TOP].Amount
#define InfoTopLokasi(S) (S).T[(S).TOP].Position

#define ActionName(A) (A).Name
#define ActionType(A) (A).Type
#define ActionTime(A) (A).Time
#define ActionAmount(A) (A).Amount
#define ActionPosition(A) (A).Position

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackAction (StackAction *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackAction (StackAction S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackAction (StackAction S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushAction (StackAction * S, Action X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopAction (StackAction * S, Action * X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
