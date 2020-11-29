#include <stdio.h>
#include "boolean.h"
#include "tree.h"
#include "..\mesinkata\mesinkar.h"

int main()
{
    /* Kamus */ 
    Tree T, Tnew, Tstring, idx;
    addressTree Tadd;
    int in;

    /* Algoritma */ 
    AlokasiTree(&Tadd, 50);
    BuildTree(&T);
    in = 50;
    idx = 4;

    Tnew = BuildBalanceTree(4, &in);


    BuildTreeFromString(&Tstring, )
    return 0;
}