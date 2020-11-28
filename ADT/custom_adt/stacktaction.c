/* File : stack.c */

#include <stdio.h>
#include "stacktaction.h"
#include "boolean.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (StackAction *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (StackAction S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)== Nil);
}
boolean IsFull (StackAction S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S)== MaxElStack-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (StackAction * S, actiontype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) +=1;
    InfoTop(*S)=X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (StackAction * S, actiontype * X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

/* menginvers Stack */
void InversStack (StackAction * S)
/*I.S : Stack tidak mungkin kosong */
/*F.S : Stack menjadi terbalik */
{
    StackAction temp;
    actiontype x;
    CreateEmpty(&temp);
    while !(IsEmpty(*S)){
        Pop(S,&x);
        Push(&temp,x);
    }
    *S = temp;
}