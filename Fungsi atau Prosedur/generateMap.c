/* Prosedur untuk mengenerate map */

#include <stdlib.h>
#include <stdio.h>
#include "player.h"


void geneateMapMain(Player P, Stack Aksi)
{
    JAM buka, tutup;
    buka = MakeJAM(9,0,0);
    tutup = MakeJam(21,0,0);
    if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
        printf("Main phase Day %d\n",Day(P));
    }
    else{
        printf("Preparation phase Day %d\n",Day(P));
    }
    /*generating map */
    printMap(P);

    printf("Legend :\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, v, > = Gerbang\n");
    printf("\n");
    printf("Name : %s \n",Name(P));
    printf("Money : %d \n",Money(P));
    printf("Current time : ")
    TulisJAM(Time(P));
    printf('\n');

    if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
        printf("Closing time : ");
        TulisJAM(tutup);
        printf("\n");
        printf("Time remaining : ");
        cetakDurasi(Durasi(Time(P),tutup));
        printf("\n");
        /* buat prosedur print antrian */
    }
    else{
        printf("Opening time : ");
        TulisJAM(buka);
        printf("\n");
        printf("Time remaining : ");
        cetakDurasi(Durasi(Time(P),buka));
        printf("\n");
        printf("Jumlah aksi yang akan dilakukan : %d\n",(Top(Aksi)+1));
        printf("Total waktu yang dibutuhkan : "); TulisJAM(HitungTime(Aksi));
        printf("\n");
        printf("Total uang yang dibutuhkan : ",HitungMoney(Aksi));
    }
    
    
    if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
        printf("Closing time : ");
        TulisJAM(tutup);
        printf("\n")
    }

    printf("Masukkan perintah : \n");
}
