/************** ADT PLAYER **************/

#ifndef player_H
#define player_H

#include <stdlib.h>
#include <stdio.h>
#include "../Jam/jam.h"
#include "../point/point.h"
#include "../mesinkata/mesinkata.h"

typedef struct{
    int wood;
    int stone;
    int iron;
}Material;

typedef struct{
  Kalimat Name;
  JAM CurrentTime;
  int Day;
  POINT Position;
  int Money;
  Material Material;
  int Debt;
} Player;


// typedef struct
// {
// 	Kalimat Name;
// 	int Money;
// 	Material Mat;
// 	Point Pos;
// } Player;

/* P adalah player, M adalah Material */
#define Name(P) (P).Name
#define Time(P) (P).CurrentTime
#define Day(P) (P).Day
#define Position(P) (P).Position
#define Money(P) (P).Money
#define Material(P) (P).Material
#define Debt(P) (P).Debt

#define Wood(M) (M).wood
#define Stone(M) (M).stone
#define Iron(M) (M).iron

/* ************ Prototype ************ */
void addMoney (Player *P, int X);
/* menambahkan uang player sebanyak X */

void addMaterial(Player *P, int wood, int stone, int iron);
/* menambahkan atau mengurangi (jika input minus) material yang dimiliki player */

void nextDay(Player *P);
/* hari maju sebanyak 1 hari */

void createEmptyMaterial (Material *Mat);

void addTime(Player *P, long X);
/* menambahkan waktu yang dilewati player sebanyak X (dalam detik) */

#endif