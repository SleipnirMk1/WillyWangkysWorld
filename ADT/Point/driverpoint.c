/* File: driverpoint.c */

#include <stdio.h>
#include "boolean.h"
#include "point.h"

int main ()
{
    POINT P1, P2;
    float dx, dy;
    int da;

    /* Test Baca dan TUlis */
    printf("Masukkan nilai absis dan ordinat P1: \n");
    BacaPOINT(&P1);
    printf("Masukkan nilai absis dan ordinat P2: \n");
    BacaPOINT(&P2);

    printf("Titik P1 yang dibaca: ");
    TulisPOINT(P1);
    printf("\n");
    printf("Titik P2 yang dibaca: ");
    TulisPOINT(P2);
    printf("\n \n");

    /* Test Relasional */
    printf("Apakah P1 dan P2 sama? \n");
    if(EQ(P1,P2))
    {
        printf("Ya \n");
    } else
    {
        printf("Tidak \n");
    }
    printf("Apakah P1 dan P2 berbeda? \n");
    if(NEQ(P1,P2))
    {
        printf("Ya \n");
    } else
    {
        printf("Tidak \n");
    }
    printf("\n");

    /* Test Posisi */
    if (IsOrigin(P1))
    {
        printf("P1 adalah titik origin \n");
    } else
    {
        printf("P1 bukan titik origin \n");
    }

    if (IsOnSbX(P1))
    {
        printf("P1 terletak di sumbu X \n");
    } else
    {
        printf("P1 tidak terletak di sumbu X \n");
    }

    if (IsOnSbY(P1))
    {
        printf("P1 terletak di sumbu Y \n");
    } else
    {
        printf("P1 tidak terletak di sumbu Y \n");
    }

    printf("P1 berada di kuadran: %d\n\n", Kuadran(P1));

    /* Test Operasi Lain */
    printf("Absis P1 jika ditambah 1 akan menjadi: ");
    TulisPOINT(NextX(P1));
    printf("\n");

    printf("Ordinat P1 jika ditambah 1 akan menjadi: ");
    TulisPOINT(NextY(P1));
    printf("\n");

    printf("Area P1 jika ditambah 1 akan menjadi: ");
    TulisPOINT(NextA(P1));
    printf("\n");

    printf("Jika ordinat, absis, dan area P1 masing-masing ditambah 3, 2, dan 1 akan menjadi: ");
    TulisPOINT(PlusDelta(P1,2,3,1));
    printf("\n");
    
    print("Pencerminan P1 terhadap sumbu Y adalah: ");
    TulisPOINT(MirrorOf(P1,false));
    printf("\n");

    printf("Jarak P1 terhadap titik origin adalah: %f\n", Jarak0(P1));

    printf("Jarak P1 terhadap P2 adalah: %f\n", Panjang(P1,P2));

    printf("Jika P1 digeser 3 satuan ke kanan dan 4 satuan ke atas hasilnya adalah: ");
    Geser(&P1,3,4,0);
    TulisPOINT(P1);
    printf("\n");

    printf("Jika P2 digeser ke sumbu X, hasilnya adalah: ");
    GeserKeSbX(&P2);
    TulisPOINT(P2);
    printf("\n");

    printf("Jika P1 digeser ke sumbu Y, hasilnya adalah: ");
    GeserKeSbY(&P1);
    TulisPOINT(P1);
    printf("\n");

    printf("Jika P1 dicerminkan terhadap sumbu X, hasilnya adalah: ");
    Mirror(&P1,true);
    TulisPOINT(P1);
    printf("\n");

    printf("Jika P2 diputar 90 derajat searah jarum jam, hasilnya adalah: ");
    Putar(&P2, 90);
    TulisPOINT(P2);

    return 0;
}
