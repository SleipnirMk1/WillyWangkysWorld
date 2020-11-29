/* File: point.h */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct {
	float X; /* absis   */
	float Y; /* ordinat */
   int A;
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define Area(P) (P).A

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y, int A);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P);
/* Membaca nilai absis, ordinat, dan area dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis, ordinat, dan area tersebut */
/* Komponen X, Y, dan A dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 3
   akan membentuk POINT <1,2,3> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y,A)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
	Output Area dituliskan dalam integer
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y,Z)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
/* Serta Area nya sama */
boolean NEQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */
/* Sudah memperhitungkan area */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* Menghasilkan true jika P adalah titik origin dalam suatu area */
boolean IsOnSbX (POINT P);
/* Menghasilkan true jika P terletak Pada sumbu X pada suatu area */
boolean IsOnSbY (POINT P);
/* Menghasilkan true jika P terletak pada sumbu Y pada suatu area */
int Kuadran (POINT P);
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 dalam suatu area */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P);
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P);
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT NextA (POINT P);
/* Mengirim salinan P dengan Area ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY, int deltaP);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
/* serta Area(P) + deltaA (Bisa negatif) */
POINT MirrorOf (POINT P, boolean SbX);
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu dalam suatu area */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P);
/* Menghitung jarak P ke (0,0,A) */
float Panjang (POINT P1, POINT P2);
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Hanya digunakan untuk mengukur panjang dalam satu area yang sama, tidak berbeda area */
void Geser (POINT *P, float deltaX, float deltaY, int deltaA);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
/* Serta menggeser Area sebesar deltaA (Bisa negatif) */
void GeserKeSbX (POINT *P);
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9,1), maka menjadi (9,0,1) */
void GeserKeSbY (POINT *P);
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9,1), maka menjadi (0,9,1) */
void Mirror (POINT *P, boolean SbX);
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut);
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam, masih dalam area yang sama */

#endif