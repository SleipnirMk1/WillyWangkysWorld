#include <stdlib.h>
#include <stdio.h>
#include "queueAntrian.h"
#include "boolean.h"
#include "..\mesinkata\mesinkata.h"
#include "..\custom_adt\arraywahana.h"

int main()
{
    /* Kamus */ 
    QueueAntrian QueAntri, QueEmpty;
    infotype X;
    infotype var;
    ArrayWahana TI;

    /* Algoritma */ 
    PrioAntrian(var) = 1;
    InfoAntrian(var) = TI[49];

    MakeEmptyQueueAntrian(&QueAntri, 5);

    /* cek apakah kosong */
    if (IsEmptyQueueAntrian(QueAntri))
    {
        printf("Antrian kosong !\n");
    }
    else
    {
        printf("Antrian tidak kosong !\n");
    }
    printf("Banyak elemen antrian : %d\n", NBElmtQueueAntrian(QueAntri));
    
    /* tambah elemen saat kosong */
    EnqueueAntrian(&QueAntri, 50);
    printf("tambah elemen 50\n");
    PrintQueueAntrian(QueAntri);

    /* tambah elemen saat tidak kosong */
    EnqueueAntrian(&QueAntri, 75);
    printf("tambah elemen 50\n");
    PrintQueueAntrian(QueAntri);

    /* kurangi elemen */
    DequeueAntrian(&QueAntri, &X);
    printf("elemen dihapus dengan aturan fifo\n");
    PrintQueueAntrian(QueAntri);

    return 0;
}