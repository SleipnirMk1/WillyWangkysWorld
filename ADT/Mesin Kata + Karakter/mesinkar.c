/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

#define MAX 100

char CC;
boolean EOP;

char PITA[MAX];
int idx = 0;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	//pita = stdin;
  idx = 0;
  fgets(PITA, sizeof(PITA), stdin);
  while(idx < MAX && PITA[idx] != '\n')
    idx++;

  if (idx != MAX)
    PITA[idx] = MARK;
  else
    PITA[idx-1] = MARK;

  idx = 0;

	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	//retval = fscanf(pita,"%c",&CC);
	
  CC = PITA[idx++];
  EOP = (CC == MARK);

}