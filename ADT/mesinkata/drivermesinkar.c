#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"

int main()
{
    /* Kamus */ 

    /* Algoritma */
    printf("Testing dimulai !"); 
    START();
    while (!EOP)
    {
        /* print karakter dari isi kata */
        printf("%c, ", CC);
        /* Karakter menelusuri hingga ada MARK (.) */
        ADV();
    }
    
    return 0;
}