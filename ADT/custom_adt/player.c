#include "player.h"
#include <stdio.h>


/* ************ Prototype ************ */
void addMoney (Player *P, int X)
{
    Money(*P) = Money(*P) + X;
}

void addMaterial(Player *P, int wood, int stone, int iron)
{
    Wood(Material(*P)) = Wood(Material(*P)) + wood;
    Stone(Material(*P)) = Stone(Material(*P)) + stone;
    Iron(Material(*P)) = Iron(Material(*P)) + iron;
}

void nextDay(Player *P)
{
    Day(*P) = Day(*P)+1;
}

void createEmptyMaterial(Material *Mat)
{
    Wood(*Mat) = 0;
    Stone(*Mat) = 0;
    Iron(*Mat) = 0;
    // Mamank(*Mat) = 0;
}

void addTime(Player *P, long X)
{
    long detik;
    detik = JAMToDetik(Time(*P));
    detik = detik + X;
    Time(*P) = DetikToJAM(detik);
}