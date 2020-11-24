/* File: point.c */

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y, int A)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	POINT P;
	
	Absis(P) = X;
	Ordinat(P) = Y;
	Area(P) = A;

	return P;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	float x, y, a;
	
	scanf("%f\n", &x);
	scanf("%f\n", &y);
	scanf("%f\n", &a);
	*P = MakePOINT(x, y, a);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
	printf("(%.2f,%.2f,%d)", Absis(P), Ordinat(P), Area(P));
}


/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
/* Serta Area nya sama */
{
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)) && (Area(P1) == Area(P2)));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
/* Sudah memperhitungkan area */
{
	return !EQ(P1, P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
	return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
	return (Absis(P) == 0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
	if ((Absis(P) > 0) && (Ordinat(P) > 0))
	{
		return 1;
	}
	else if ((Absis(P) < 0) && (Ordinat(P) > 0))
	{
		return 2;
	}
	else if ((Absis(P) < 0) && (Ordinat(P) < 0))
	{
		return 3;
	}
	else
	{
		return 4;
	}
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
	return MakePOINT(Absis(P) + 1, Ordinat(P), Area(P));
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	return MakePOINT(Absis(P), Ordinat(P) + 1, Area(P));
}
POINT NextA (POINT P)
/* Mengirim salinan P dengan Area ditambah satu */
{
	return MakePOINT(Absis(P), Ordinat(P), Area(P) + 1);
}
POINT PlusDelta (POINT P, float deltaX, float deltaY, int deltaA)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY, Area(P) + deltaA);
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
	if (SbX)
	{
		return MakePOINT(Absis(P), ((-1) * Ordinat(P)), Area(P));
	}
	else
	{
		return MakePOINT(((-1) * Absis(P)), Ordinat(P), Area(P));
	}
	
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
	float x  = (Absis(P) * Absis(P)) + (Ordinat(P) * Ordinat(P));
	return sqrt(x);
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Hanya digunakan untuk mengukur panjang dalam satu area yang sama, tidak berbeda area */
/* Jika digunakan untuk mengukur panjang 2 point beda area, akan mengembalikan hasil seolah-olah satu area */
{
	float x, y;

	x = Absis(P1) - Absis(P2);
	y = Ordinat(P1) - Ordinat(P2);
	
	return sqrt((x * x) + (y * y));
}
void Geser (POINT *P, float deltaX, float deltaY, int deltaA)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
/* Serta menggeser Area sebesar deltaA (Bisa negatif) */
{
	*P = PlusDelta(*P, deltaX, deltaY, deltaA);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
	*P = MakePOINT(Absis(*P), 0, Area(*P));
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
	*P = MakePOINT(0, Ordinat(*P), Area(*P));
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
	*P = MirrorOf(*P, SbX);
}
void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
{
	*P = MakePOINT(((Absis(*P) * cos(Sudut)) + (-1) * Ordinat(*P) * sin(Sudut) ), ((Absis(*P) * sin(Sudut)) + (Ordinat(*P) * cos(Sudut))), Area(*P));
}
