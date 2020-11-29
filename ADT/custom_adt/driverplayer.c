#include "../Jam/jam.h"
#include "player.h"
#include <stdio.h>

int main()
{
    /* Kamus */ 
    Player P1;

    /* Algoritma */ 
    Money(P1) = 250;
    Day(P1) = 1;

    /* Tambah uang */
    addMoney(&P1, 500);
    printf("Uang bertambah 500 : %d\n", Money(P1));
    addMoney(&P1, -500);
    printf("Uang berkurang 500 : %d\n", Money(P1));

    /* add material */
    addMaterial(&P1, 500, 100, 275);
    printf("wood : %d\n", Wood(Material(P1)));
    printf("stone : %d\n", Stone(Material(P1)));
    printf("iron : %d\n", Iron(Material(P1)));

    /* nextday */
    nextDay(&P1);
    printf("sekarang hari jumat.\n");
    if (Day(P1) == 2)
    {
        printf("sekarang hari sabtu.\n");
    }
    else
    {
        printf("dunia kiamat !\n");
    }
    /* add time */
    addTime(&P1, 3600);
    printf("jam setelah bertambah :\n");
    TulisJAM(Time(P1));
    return 0;
}