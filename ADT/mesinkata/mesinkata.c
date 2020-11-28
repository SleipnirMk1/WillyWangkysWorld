// NIM : 13519051
// Nama : Yudi Alfayat
// Pra Praktikum 6
// file mesinkata.c

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

// #define MAXSTACK 15
// #define IdxMin(S) (S).IdxMin
// #define IdxMax(S) (S).IdxMax 
// #define IDXNIL -1

// typedef struct 
// {
//   Kata Elmt[MAXSTACK];
//   int IdxMin;
//   int IdxMax;
// } QueueKata;


/* State Mesin Kata */
boolean EndKata;
Kata CKata;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while(!EOP && CC == BLANK)
    {
        ADV();
    }
}


void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();

    if (EOP)
    {
        EndKata = true;
        CKata.Length = 0;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}


void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();

    if (EOP)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
        IgnoreBlank();
    }
}


void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while (!EOP && CC != BLANK && i < NMax)
    {
        CKata.TabKata[i] = CC;
        i++;

        ADV();
    }
    CKata.TabKata[i] = '\0';
    CKata.Length = i;
}


void SetKata(Kata *K, char arr[])
{
  int n = 0;
  while (arr[n] != '\0' && arr[n] != ' ')
    n++;

  for (int i = 0; i < n; ++i)
  {
    (*K).TabKata[i] = arr[i];
  }
  (*K).TabKata[n] = '\0';

  (*K).Length = n;
}

Kalimat SetKalimat(char arr[])
{
  Kalimat kalimat;
  CreateEmptyKalimat(&kalimat);

  STARTWITH(arr);
  IgnoreBlank();

  if (EOP)
  {
      EndKata = true;
      CKata.Length = 0;
  }
  else
  {
      EndKata = false;
      SalinKata();
  }

  while(!EndKata)
  {
    EnqueueKalimat(&kalimat, CKata);
    ADVKATA();
  }

  return kalimat;
}

Kalimat GetKalimat()
{
  Kalimat kalimat;
  CreateEmptyKalimat(&kalimat);

  STARTKATA();

  while(!EndKata)
  {
    EnqueueKalimat(&kalimat, CKata);
    ADVKATA();
  }

  return kalimat;
}


void PrintKata(Kata K)
{
  for (int i = 0; i < K.Length; ++i)
  {
    printf("%c", K.TabKata[i]);
  }
}

boolean IsEmptyKalimat(Kalimat S)
{
  return IdxMin(S) == IDXNIL && IdxMax(S) == IDXNIL;
}

void CreateEmptyKalimat(Kalimat *S)
{
  IdxMin(*S) = IDXNIL;
  IdxMax(*S) = IDXNIL;
}

void EnqueueKalimat(Kalimat *S, Kata K)
{
  if (IsEmptyKalimat(*S))
  {
    IdxMin(*S) = 0;
    IdxMax(*S) = 0;
    (*S).Elmt[0] = K;
  }
  else
  {
    IdxMax(*S)++;
    (*S).Elmt[IdxMax(*S)] = K;
  }
}

void DequeueKalimat(Kalimat *S, Kata *K)
{
  if (IsEmptyKalimat(*S))
  {
    SetKata(K, " ");
  }
  else if (NbKata(*S) == 1)
  {
    *K = (*S).Elmt[IdxMin(*S)];
    IdxMin(*S) = IDXNIL;
    IdxMax(*S) = IDXNIL;
  }
  else
  {
    *K = (*S).Elmt[IdxMin(*S)];
    IdxMax(*S)--;
    for (int i = IdxMin(*S); i <= IdxMax(*S); ++i)
    {
      (*S).Elmt[i] = (*S).Elmt[i+1];
    }
  }
}

int NbKata(Kalimat S)
{
  if (IsEmptyKalimat(S))
    return 0;
  else
    return IdxMax(S)-IdxMin(S) + 1;
}

void PrintKalimat(Kalimat S)
{
  int n = NbKata(S);
  for(int i = 0; i < n; i++)
  {
    Kata K;
    DequeueKalimat(&S, &K);
    PrintKata(K);

    if (i != n-1)
      printf(" ");
  }
}

boolean IsEQKalimat(Kalimat Q1, Kalimat Q2)
{
  if (NbKata(Q1) == NbKata(Q2))
  {
    boolean same = true;
    while(!IsEmptyKalimat(Q1) && same)
    {
      Kata K1, K2;
      DequeueKalimat(&Q1, &K1);
      DequeueKalimat(&Q2, &K2);

      if (!KataSama(K1, K2))
        same = false;
    }

    return same;
  }
  else
  {
    return false;
  }
}

boolean KataSama(Kata K1, Kata K2)
{
  if (K1.Length != K2.Length)
  {
    return false;
  }
  else
  {
    boolean same = true;
    int i = 0;
    while(i < K1.Length && same)
    {
      if (K1.TabKata[i] != K2.TabKata[i])
        same = false;
      else
        i++;
    }

    return same;
  }
}

int NbHurufKalimat(Kalimat Q)
{
  int n = 0;
  while(!IsEmptyKalimat(Q))
  {
    Kata K;
    DequeueKalimat(&Q, &K);
    n += K.Length;
  }

  return n;
}

int KataToInteger(Kata K)
{
  return atoi(K.TabKata);
}


