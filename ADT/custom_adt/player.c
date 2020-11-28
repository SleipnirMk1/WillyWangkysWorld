#include "player.h"
#include <stdio.h>


/* ************ Prototype ************ */
void addMoney (Player *P, int X)
{
    Money(*P) = Money(*P) + X;
}

void addMaterial(Player *P, int wood, int stone, int iron, int mamank)
{
    Wood(Material(*P)) = Wood(Material(*P)) + wood;
    Stone(Material(*P)) = Stone(Material(*P)) + stone;
    Iron(Material(*P)) = Iron(Material(*P)) + iron;
    //Mamank(Material(*P)) = Mamank(Material(*P)) + mamank;
}

void nextDay(Player *P)
{
    Day(*P) = Day(*P)+1;
}
