/* File : stack.c */

#include <stdio.h>
#include "stackaction.h"
#include "boolean.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackAction (StackAction *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackAction (StackAction S)
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
void PushAction (StackAction * S, Action X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) +=1;
    InfoTop(*S)=X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopAction (StackAction * S, Action * X)
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
    Action x;
    CreateEmptyStackAction(&temp);
    while (!IsEmptyStackAction(*S)){
        PopAction(S,&x);
        PushAction(&temp,x);
    }
    *S = temp;
}

int NbElmtStackAction(StackAction S)
{
    int i = 0;
    while(!IsEmptyStackAction(S))
    {
        Action A;
        PopAction(&S, &A);
        i++;
    }

    return i;
}

int TotalTimeAction(StackAction S)
{
    int n = NbElmtStackAction(S);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        Action A;
        PopAction(&S, &A);

        sum += ActionTime(A);
    }
    
    return sum;
}