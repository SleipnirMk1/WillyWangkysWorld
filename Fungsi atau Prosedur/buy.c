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


void Buy(Stackt *S)
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
    char input[20];
    printf("Masukan pilihan :");
    scanf("%s",&input);
    /* Parsing perintah pengguna */
    /* menggunakan mesin kata input di parse menjadi banyak barang dan jeni barang */

    /* kalo kondisi input valid : */
    i = SearchList(namaMaterial,inputnama);
    int totalHarga = hargaMaterial[i]*inputbanyak;
    /* memasukkan ke stack */
    infotypeStack X;
    JAM J;
    /* (masih pemisalan) membeli 1 material membutuhkan waktu 5 menit */
    long lama = 300*inputbanyak
    J = DetikToJam(lama);
    InfoJenisAksi(X)= "buy";
    InfoLamaAksi(X)= L;
    InfoUangYangDibutuhkan = totalHarga;
    Push(S,X);
    fclose(material);

}

int main()
{
    Stack S;
    CreateEmpty(&S);
    Buy(&S);

    return 0;
}
