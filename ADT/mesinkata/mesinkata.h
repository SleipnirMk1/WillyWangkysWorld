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
} QueueKata;



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
boolean IsEmpty(QueueKata S);
void CreateEmpty(QueueKata *S);
void EnqueueKata(QueueKata *S, Kata K);
void DequeueKata(QueueKata *S, Kata *K);
int NbElmt(QueueKata S);
void PrintKata(Kata K);
void PrintQueueKata(QueueKata S);
QueueKata GetQueueKata();
boolean IsEQ(QueueKata Q1, QueueKata Q2);
boolean KataSama(Kata K1, Kata K2);
QueueKata SetQueueKata(char arr[]);


#endif
