/* File: drivermatriks.c */

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

int main ()
{
    int NB = 2;
    int NK = 2;
    MATRIKS M1, M2;

    /* Test Baca, Tulis, Konstruktor, dan Assignment */
    printf("Masukkan matriks M1: \n");
    BacaMATRIKS(&M1, NB, NK);
    
    CopyMATRIKS(M1, &M2);

    printf("Hasil copy matriks yang dibaca: ");
    TulisMATRIKS(M2);
    printf("\n");

    /* Test Selektor */
    indeks a = GetFirstIdxBrs(M1);
    print("Indeks baris pertama matriks tersebut: %d\n", a);

    a = GetLastIdxBrs(M1);
    print("Indeks baris terakhir matriks tersebut: %d\n", a);

    a = GetFirstIdxKol(M1);
    print("Indeks kolom pertama matriks tersebut: %d\n", a);

    a = GetLastIdxKol(M1);
    print("Indeks kolom pertama matriks tersebut: %d\n", a);

    boolean bolean = IsIdxValid(1, 2);
    if (bolean)
    {
        print("(1,2) adalah indeks yang valid dalam matriks\n");
    }
    else
    {
        print("(1,2) adalah indeks yang tidak valid dalam matriks\n");
    }
    
    bolean = IsIdxEff(1, 2);
    if (bolean)
    {
        print("(1,2) adalah indeks yang efektif dalam matriks\n");
    }
    else
    {
        print("(1,2) adalah indeks yang tidak efektif dalam matriks\n");
    }

    ElType b = GetElmtDiagonal(M1, 1);
    print("%c adalah elemen diagonal (1,1) matriks\n", b);

    /* Test Relasional */
    printf("Apakah M1 dan M2 sama? \n");
    if(EQ(M1,M2))
    {
        printf("Ya \n");
    } else
    {
        printf("Tidak \n");
    }
    printf("Apakah M1 dan M2 berbeda? \n");
    if(NEQ(M1,M2))
    {
        printf("Ya \n");
    } else
    {
        printf("Tidak \n");
    }
    printf("\n");
    printf("Apakah M1 dan M2 ukuran sama? \n");
    if(EQSize(M1,M2))
    {
        printf("Ya \n");
    } else
    {
        printf("Tidak \n");
    }
    printf("\n");

    /* Kelompok test terhadap matriks */
    if (IsBujurSangkar(M1))
    {
        printf("Matriks adalah bujur sangkar\n");
    } else
    {
        printf("Matriks bukan bujur sangkar\n");
    }

    if (IsSparse(M1))
    {
        printf("Matriks jarang\n");
    } else
    {
        printf("Matriks tidak jarang\n");
    }

    Transpose(&M1);
    printf("Hasil transpose:\n");
    TulisMATRIKS(M1);

    return 0;
}
