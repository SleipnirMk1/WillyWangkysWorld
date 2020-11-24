// NIM          : 13519127
// Nama         : Giant Andreas Tambunan

/* file: listlinier.c */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *E = (ElmtList *)malloc(sizeof(ElmtList));

    if (E == Nil){
        return Nil;
    }
    else {
        Info(E) = X;
        Next(E) = Nil;
        return E;
    }

}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    if (IsEmpty(L)){
        return Nil;
    }
    else{
        boolean found = false;
        address Elmt = First(L);
        while ( (!found) && Elmt != Nil){
            if (Info(Elmt) == X){
                found = true;
            }
            else{
                Elmt = Next(Elmt);
            }
        }
        return Elmt;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address Elmt;
    Elmt = Alokasi(X);
    if (Elmt != Nil){
        InsertFirst(L, Elmt );
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address Elmt;
    Elmt = Alokasi(X);
    if (Elmt != Nil){
        Next(Elmt) = First(*L);
        InsertLast(L, Elmt);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address Elmt;
    DelFirst(L, &Elmt);
    *X = Info(Elmt);
    Dealokasi(&Elmt);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address Elmt;
    DelLast(L, &Elmt);
    *X = Info(Elmt);
    Dealokasi(&Elmt);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)){
        InsertFirst(L,P);
    }
    else{
        address last;
        last = First(*L);
        while (Next(last) != Nil){
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    address Elmt;
    Elmt = First(*L);
    First(*L) = Next(Elmt);
    *P = Elmt;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address Elmt;
    Elmt = Search(*L, X);

    if (Elmt != Nil){
        address prec;
        prec = First(*L);
        if (prec == Elmt){
            DelFirst(L, &prec);
        }
        else{
            while (Next(prec) != Elmt){
                prec = Next(prec);
            }
            DelAfter(L, &Elmt, prec);
        }
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address Elmt;
    address prec;
    Elmt = First(*L);
    if (Next(Elmt) == Nil){
        DelFirst(L, &Elmt);
        *P = Elmt;
    }
    else{
        Elmt = Next(Elmt);
        prec = First(*L);
        while (Next(Elmt) != Nil){
            Elmt = Next(Elmt);
            prec = Next(prec);
        }
        DelAfter(L, &Elmt, prec);
        *P   = Elmt;
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    address Elmt;
    if (Next(Prec) != Nil ){
        Elmt = Next(Prec);
        Next(Prec) = Next(Elmt);
    }
    *Pdel = Elmt;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (IsEmpty(L)){
        printf("[]");
    }
    else{
        printf("[");
        address Elmt = First(L);
        while (Next(Elmt) != Nil){
            printf("%d,",Info(Elmt));
            Elmt = Next(Elmt);
        }
        printf("%d]",Info(Elmt));
    }
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{

    int count = 0;
    address Elmt = First(L);
    while (Elmt != Nil ){
        count = count +1;
        Elmt = Next(Elmt);
    }
    return count;
}

/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
    address Elmt;
    Elmt = First(L);
    infotype min = Info(Elmt);
    while (Elmt != Nil){
        if (Info(Elmt) < min){
            min = Info(Elmt);
        }
        Elmt = Next(Elmt);
    }
    return min;
}


/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address Elmt;
    Elmt = First(L);
    infotype max = Info(Elmt);
    while (Elmt != Nil){
        if (Info(Elmt) > max){
            max = Info(Elmt);
        }
        Elmt = Next(Elmt);
    }
    return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);
    if (!IsEmpty(*L1)){
        address Elmt;
        Elmt = First(*L1);
        First(*L3) = First(*L1);
        while (Next(Elmt) != Nil){
            Elmt = Next(Elmt);
        }
        Next(Elmt) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
