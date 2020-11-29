#include <stdio.h>
#include "boolean.h"
//#include "jam.h"
#include "../point/point.h"
#include "../mesinkata/mesinkata.h"
#include "player.h"
//#include "../listBerkait/listlinier.h"

#ifndef WAHANA_H
#define WAHANA_H

// #define Nil -1;

/* *** Definisi TYPE WAHANA *** */
typedef struct {
	Kalimat Name;
    int Type;
    boolean Condition;
    int PriceCost;
    Material MaterialCost;
    POINT Position;
    Kalimat Deskripsi;
    int Capacity;
    int PlayTime;
    int Profit;
    int UsedAmount;
    int TotalProfit;
    int UsedToday;
    int ProfitToday;
    //List Upgrade;
} WAHANA;

/* *** Notasi Akses: WAHANA *** */
#define Nama(P) (P).Name
#define Tipe(P) (P).Type
#define Condition(P) (P).Condition
#define Price(P) (P).PriceCost
#define MaterialCost(P) (P).MaterialCost
#define Lokasi(P) (P).Position
#define Deskripsi(P) (P).Deskripsi
#define Kapasitas(P) (P).Capacity
#define PlayTime(P) (P).PlayTime
#define Profit(P) (P).Profit
#define TotalNaik(P) (P).UsedAmount
#define TotalProfit(P) (P).TotalProfit
#define TodayNaik(P) (P).UsedToday
#define TodayProfit(P) (P).ProfitToday
#define UpgradeHistory(P) (P).Upgrade

#endif