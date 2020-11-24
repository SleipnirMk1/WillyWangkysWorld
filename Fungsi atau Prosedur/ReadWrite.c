#include <stdio.h>
#include <stdlib.h>

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
