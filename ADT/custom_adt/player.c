/* File : player.c */
/************** REALISASI ADT PLAYER **************/
#include "player.h"
#include <stdio.h>


/* ************ Prototype ************ */
void addMoney (Player *P, int X)
/* menambahkan uang player sebanyak X */
{
    Money(*P) = Money(*P) + X;
}

void addMaterial(Player *P, int wood, int stone, int iron)
/* menambahkan atau mengurangi (jika input minus) material yang dimiliki player */
{
    Wood(Material(*P)) = Wood(Material(*P)) + wood;
    Stone(Material(*P)) = Stone(Material(*P)) + stone;
    Iron(Material(*P)) = Iron(Material(*P)) + iron;
}

void nextDay(Player *P)
/* hari maju sebanyak 1 hari */
{
    Day(*P) = Day(*P)+1;
}

void createEmptyMaterial(Material *Mat)
// membuat struct material yang setiap elemennya bernilai 0
{
    Wood(*Mat) = 0;
    Stone(*Mat) = 0;
    Iron(*Mat) = 0;
    // Mamank(*Mat) = 0;
}

void addTime(Player *P, long X)
/* menambahkan waktu yang dilewati player sebanyak X (dalam detik) */
{
    long detik;
    detik = JAMToDetik(Time(*P));
    detik = detik + X;
    Time(*P) = DetikToJAM(detik);
}