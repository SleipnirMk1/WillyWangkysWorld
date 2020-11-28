#include <stdlib.h>
#include <stdio.h>
#include "matriks.c"
#include "boolean.h"


/* Prosedur mengisi matriks Map1 dengan map1.txt */
void Map1(MATRIKS *Map1)
{
    FILE *maptxt;
    maptxt = fopen("map1.txt","r");
    if(maptxt == NULL){
        printf("reading file failed\n");
        exit(1);
    }
    char CC;
    int i = 0;
    int j = 0;
    MakeMATRIKS(10,19,Map1);
    while(feof(maptxt) == 0){
        fscanf(maptxt,"%c",&CC);
        printf("%c",CC);
        if(CC == '\n'){
            i = i+1;
            j = 0;
        }
        else{
            Elmt(*Map1,i,j) = CC;
            j = j+1;
        }
    }

    fclose(maptxt);
    return 0;
}


/* Prosedur mengisi matriks Map2 dengan map2.txt */
void Map2(MATRIKS *Map2)
{
    FILE *maptxt;
    maptxt = fopen("map2.txt","r");
    if(maptxt == NULL){
        printf("reading file failed\n");
        exit(1);
    }
    char CC;
    int i = 0;
    int j = 0;
    MakeMATRIKS(10,19,Map2);
    while(feof(maptxt) == 0){
        fscanf(maptxt,"%c",&CC);
        printf("%c",CC);
        if(CC == '\n'){
            i = i+1;
            j = 0;
        }
        else{
            Elmt(*Map2,i,j) = CC;
            j = j+1;
        }
    }

    fclose(maptxt);
    return 0;
}


/* Prosedur mengisi matriks Map3 dengan map3.txt */
void Map3(MATRIKS *Map3)
{
    FILE *maptxt;
    maptxt = fopen("map3.txt","r");
    if(maptxt == NULL){
        printf("reading file failed\n");
        exit(1);
    }
    char CC;
    int i = 0;
    int j = 0;
    MakeMATRIKS(10,19,Map3);
    while(feof(maptxt) == 0){
        fscanf(maptxt,"%c",&CC);
        printf("%c",CC);
        if(CC == '\n'){
            i = i+1;
            j = 0;
        }
        else{
            Elmt(*Map3,i,j) = CC;
            j = j+1;
        }
    }

    fclose(maptxt);
    return 0;
}


/* Prosedur mengisi matriks Map4 dengan map4.txt */
void Map4(MATRIKS *Map4)
{
    FILE *maptxt;
    maptxt = fopen("map4.txt","r");
    if(maptxt == NULL){
        printf("reading file failed\n");
        exit(1);
    }
    char CC;
    int i = 0;
    int j = 0;
    MakeMATRIKS(10,19,Map4);
    while(feof(maptxt) == 0){
        fscanf(maptxt,"%c",&CC);
        printf("%c",CC);
        if(CC == '\n'){
            i = i+1;
            j = 0;
        }
        else{
            Elmt(*Map4,i,j) = CC;
            j = j+1;
        }
    }

    fclose(maptxt);
    return 0;
}
