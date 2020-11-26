#include <stdio.h>
#include "boolean.h"
#include "point.h"

#ifndef PLAYERDATA_H
#define PLAYERDATA_H

/* *** Definisi TYPE PLAYER DATA *** */
typedef struct {
	char Name[64];
    int Day;
    int Money;
    POINT Position;
} PLAYERDATA;

/* *** Notasi Akses: PLAYER DATA *** */
#define Nama(P) (P).Nama
#define Day(P) (P).Day
#define Money(P) (P).Money
#define Position(P) (P).Position

#endif