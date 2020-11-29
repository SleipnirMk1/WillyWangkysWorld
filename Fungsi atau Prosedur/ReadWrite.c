#include <stdio.h>
#include <stdlib.h>
#include "ADT\tree\tree.h"
#include "ADT\custom_adt\wahana.h"
#include "ADT\custom_adt\arraywahana.h"
#include "ADT\point\point.h"
#include "ADT\mesinkata\mesinkata.h"


void ReadMaterial(char addressFile[], int *wood, int *stone, int *iron, int *mamank) {

    FILE *fp = fopen(addressFile,"r");

    if (fp == NULL) {
        printf("Error, could not load .txt file!\n");
        exit(1);
    }

    char charA[128];
    char charB[128];
    int temp[4];
    int i = 0;
    int countLine = 1;

    while(fscanf(fp, "%s %s", &charA, &charB) != EOF) {
        if (countLine >= 2) {
            temp[i] = atoi(charB);
            ++i;
        } else {
            ++countLine;
        }
    }

    *wood = temp[0];
    *stone = temp[1];
    *iron = temp[2];
    *mamank = temp[3];

    fclose(fp);
}

void WriteMaterial(char addressFile[], int wood, int stone, int iron, int mamank) {

    FILE *fp = fopen(addressFile,"w");

    fprintf(fp, "Material Harga\n");
    fprintf(fp, "Wood %d\n", wood);
    fprintf(fp, "Stone %d\n", stone);
    fprintf(fp, "Iron %d\n", iron);
    fprintf(fp, "mamank %d\n", mamank);

    fclose(fp);
}

Tree ReadWahana(char addressFile[])
{
    FILE *fp = fopen(addressFile,"r");

    if (fp == NULL) {
        printf("Error, could not load .txt file!\n");
        exit(1);
    }

    char singleLine[128];
    Tree T;

    while (!feof(fp))
    {
        fgets(singleLine, 128, fp);
        BuildTreeFromString(&T, singleLine, 0);
    }

    return T;
    fclose(fp);
    
}

ArrayWahana ReadWahanaInfo(char addressFile[])
{
    FILE *fp = fopen(addressFile,"r");

    if (fp == NULL) {
        printf("Error, could not load .txt file!\n");
        exit(1);
    }

    ArrayWahana W;
    MakeEmptyWahana(&W);
    wahanatype X;

    Kalimat Nama;
    char Uang[16];
    char Wood[16];
    char Stone[16];
    char Iron[16];
    char Mamank[16];
    char Kapasitas[16];
    char Durasi[32];
    char Profit[16];
    Kalimat Deskripsi;
    
    int countLine = 1;
    int tipeCount = 1;

    while(fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", &Nama, &Uang, &Wood, &Stone, &Iron, &Mamank, &Kapasitas, &Durasi, &Profit, &Deskripsi) != EOF) {
        if (countLine >= 2)
        {
            Nama(X) = Nama;
            Tipe(X) = tipeCount;
            Price(X) = atoi(Uang);
            Wood(MaterialCost(X)) = atoi(Wood);
            Stone(MaterialCost(X)) = atoi(Stone);
            Iron(MaterialCost(X)) = atoi(Iron);
            Mamank(MaterialCost(X)) = atoi(Mamank);
            Kapasitas(X) = atoi(Kapasitas);
            //Durasi(X) = atoi(Durasi);       // Konversi ke detik dulu mungkin, sekarang baru konversi ke integer, value di file detik
            Profit(X) = atoi(Profit);
            Deskripsi(X) = Deskripsi;
            
            Lokasi(X) = MakePOINT(-1,-1,0); // Value Null utk lokasi wahana
            TotalNaik(X) = 0;
            TotalProfit(X) = 0;
            TodayNaik(X) = 0;
            TodayProfit(X) = 0;
            
            InsVLast(&W, X);
            ++tipeCount;
        }
        else
        {
            ++countLine;
        }
    }

    return W;
    fclose(fp);
}
