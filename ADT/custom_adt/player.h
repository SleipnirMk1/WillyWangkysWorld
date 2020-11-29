/* File : player.c */
/************** ADT PLAYER **************/

#ifndef player_H
#define player_H

/* Requirements */
#include <stdlib.h>
#include <stdio.h>
#include "../Jam/jam.h"
#include "../point/point.h"
#include "../mesinkata/mesinkata.h"

/* Material */
typedef struct{
    int wood; // kayu
    int stone;  // batuan
    int iron; // besi
}Material;

// Player
typedef struct{
  Kalimat Name;   // Nama player
  JAM CurrentTime;    // Jam sekarang di permainan
  int Day;      // Hari permainan ke berapa
  POINT Position;   // Posisi pemain
  int Money;    // Uang yang dimiliki
  int MoneyDebt;    // utang, uang yang akan dipakai
  Material Material;    // material yang dimiliki
  Material MaterialDebt;  // material yang akan dipakai
} Player;

// Notasi akses selektor player
/* P adalah player, M adalah Material */
#define Name(P) (P).Name
#define Time(P) (P).CurrentTime
#define Day(P) (P).Day
#define Position(P) (P).Position
#define Money(P) (P).Money
#define Material(P) (P).Material
#define MoneyDebt(P) (P).MoneyDebt
#define MaterialDebt(P) (P).MaterialDebt

// Notasi akses selektor material
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
// membuat struct material yang setiap elemennya bernilai 0

void addTime(Player *P, long X);
/* menambahkan waktu yang dilewati player sebanyak X (dalam detik) */

#endif