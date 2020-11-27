/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"


#define MAXSTACK 15
#define IdxMin(S) (S).IdxMin
#define IdxMax(S) (S).IdxMax 
#define IDXNIL -1


#define NMax 100
#define BLANK ' '

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
  int Length;
} Kata;


typedef struct 
{
  Kata Elmt[MAXSTACK];
  int IdxMin;
  int IdxMax;
} Kalimat;



/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA();
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void SetKata(Kata *K, char arr[]);
boolean IsEmptyKalimat(Kalimat S);
void CreateEmptyKalimat(Kalimat *S);
void EnqueueKalimat(Kalimat *S, Kata K);
void DequeueKalimat(Kalimat *S, Kata *K);
int NbKata(Kalimat S);
void PrintKata(Kata K);
void PrintKalimat(Kalimat S);
Kalimat GetKalimat();
boolean IsEQKalimat(Kalimat Q1, Kalimat Q2);
boolean KataSama(Kata K1, Kata K2);
Kalimat SetKalimat(char arr[]);
int NbHurufKalimat(Kalimat Q);


#endif
