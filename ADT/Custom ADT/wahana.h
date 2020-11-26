#include <stdio.h>
#include "boolean.h"
#include "jam.h"
#include "point.h"

#ifndef WAHANA_H
#define WAHANA_H

#define Nil -1;

/* *** Definisi TYPE WAHANA *** */
typedef struct {
	char Name[64];
    int Tipe;
    int MoneyCost;
    int WoodCost;
    int StoneCost;
    int IronCost;
    POINT Location;
    char Deskripsi[128];
    int Capacity;
    JAM Duration;
    int Profit;
    int UsedAmount;
    int TotalProfit;
    int UsedToday;
    int ProfitToday;
} WAHANA;

/* *** Notasi Akses: WAHANA *** */
#define Nama(P) (P).Name
#define Tipe(P) (P).Tipe
#define Biaya(P) (P).MoneyCost
#define Wood(P) (P).WoodCost
#define Stone(P) (P).StoneCost
#define Iron(P) (P).IronCost
#define Lokasi(P) (P).Location
#define Deskripsi(P) (P).Deskripsi
#define Kapasitas(P) (P).Capacity
#define Durasi(P) (P).Duration
#define Profit(P) (P).Profit
#define TotalNaik(P) (P).UsedAmount
#define TotalProfit(P) (P).TotalProfit
#define TodayNaik(P) (P).UsedToday
#define TodayProfit(P) (P).ProfitToday

#endif