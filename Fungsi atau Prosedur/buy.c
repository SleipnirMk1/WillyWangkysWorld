/* Fungsi Buy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackt.h"
/*
yang di include juga
stack.h
jam.h
list.h
mesinkata.h
*/


void Buy(Stack *S)
/* Prosedur untuk membeli bahan bangunan (untuk membangun wahana */
/* Dilaksanakan saat preparation phase */
/* memakan waktu */
/* Stackt aksi merupakan stack yang berisikan aksi selama preparation phase */
{

    FILE *material;
    char CC;
    char mat[10][128];
    material = fopen(".\\file\\material.txt","r");

    printf("Bahan bangunan yang ingin dibeli :\n");
    printf("Nama bahan \t\t\t Harga bahan(perbuah)\n");

     while(fgetc(material) != '\n') //skip first line
        ;
    char mater[10];
    int harga;
    int i=1;
    /* membuat list untuk menyimpan nama material dan harganya sekaligus memprint pilihan*/
    Listint namaMaterial;
    Liststring hargaMaterial;
    /* berarti untuk kasus ini ada 2 jenis list, satu infotypenya int, satulagi string */
    /* atau bisa juga satu list yang menyimpan dua duanya */
    createEmptyList(&namaMaterial);
    createEmptyList(&hargaMaterial);
    while(EOF != fscanf(material,"%s %d",&mater, &harga)){
        printf("%d. %s \t\t\t\t %d\n",i,mater, harga);
        i++;
        addLastElmt(namaMaterial, mater);
        addLastElmt(&hargaMaterial, harga);
    }

    /* meminta input untuk jenis bahan yang diberi dan harganya */
    /* rule input : <jumlah> <nama> cth : 10 mamank */
    printf("Masukan pilihan :");
    int jumlah;
    scanf("%d",jumlah);     // untuk jumlah
    QueueKata InputJenisMaterial = GetQueue()


    /* kalo kondisi input valid : */
    i = SearchList(namaMaterial,inputnama);
    int totalHarga = hargaMaterial[i]*jumlah;
    /* memasukkan ke stack */
    infotypestack X;
    JAM J;
    /* (masih pemisalan) membeli 1 material membutuhkan waktu 5 menit */
    /* membnetuk infotype stack yang akan di push ke stack aksi */
    long lama = 300*jumlah;
    J = DetikToJam(lama);
    InfoJenisAksi(X)= "buy";
    InfoLamaAksi(X)= L;
    InfoUangYangDibutuhkan(X) = totalHarga;
    Material M;
    CreateEmptyMaterial(&M);
    switch (InputJenisMaterial)
    {
    case ('Wood'):
        Wood(M) = Wood(M) + jumlah;
        break;
    case ('Stone'):
        Stone(M) = Stone(M) + jumlah;
        break;
    case ('Iron'):
        Iron(M) = Iron(M) + jumlah;
        break;
    case ('Mamank'):
        Mamank(M) = Mamank(M) + jumlah;
        break;
    
    default:
        break;
    }
    
    Material(X) = M;
    Push(S,X);
    fclose(material);

}

