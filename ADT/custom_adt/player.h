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
    int mamank;
}Material;

typedef struct{
  Kalimat Name;
  JAM CurrentTime;
  int Day;
  POINT Position;
  int Money;
  Material Material;
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
#define Wood(M) (M).wood
#define Stone(M) (M).stone
#define Iron(M) (M).iron
#define Mamank(M) (M).mamank

/* ************ Prototype ************ */
void addMoney (Player *P, int X);

void addMaterial(Player *P, int wood, int stone, int iron, int mamank);

void nextDay(Player *P);


#endif