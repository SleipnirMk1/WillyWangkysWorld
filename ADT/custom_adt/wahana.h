/* File : wahana.c */


#ifndef WAHANA_H
#define WAHANA_H

/* Requirements */
#include <stdio.h>
#include "boolean.h"
//#include "jam.h"
#include "../point/point.h"
#include "../mesinkata/mesinkata.h"
#include "player.h"
//#include "../listBerkait/listlinier.h"


/* *** Definisi TYPE WAHANA *** */
typedef struct {
	Kalimat Name;           // Nama wahana
    int Type;               // Tipe wahana
    boolean Condition;      // Kondisi rusak/tidak
    int PriceCost;          // Harga uang
    Material MaterialCost;  // Keperluan material
    POINT Position;         // Posisi wahana dalam taman bermain
    Kalimat Deskripsi;      // Deskripsi wahana
    int Capacity;           // Kapasitas pengunjung
    int PlayTime;           // Durasi digunakan
    int Profit;             // Keuntungan tiap pengunjung
    int UsedAmount;         // Total digunakan
    int TotalProfit;        // Total pendapatan
    int UsedToday;          // Penggunaan hari ini
    int ProfitToday;        // Pendapatan wahana hari ini
    //List Upgrade;         // Sejarah upgrade
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