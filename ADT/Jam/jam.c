/* File: jam.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#ifndef JAM_H
#define JAM_H

#include <stdio.h>
#include "boolean.h"
#include "jam.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}
/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM J1;
    Hour(J1) = HH;
    Minute(J1) = MM;
    Second(J1) = SS;
    return (J1);
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
    int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    do {
        scanf("%d",&HH);
    } while (IsJAMValid(HH,MM,SS));
    * J = MakeJAM(HH,MM,SS);
}
void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
{
    printf("%d:%d:%d", Hour(J),Minute(J),Second(J));
}
/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return (3600*Hour(J)+60*Minute(J)+Second(J));
}
JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    int N1, N2;
    JAM J2;
    N1 = N % 86400;
    Hour(J2) = N1/3600;
    N2 = N1 % 3600;
    Minute(J2) = N2 / 60;
    Second(J2) = N2 % 60;
    return J2;
}
/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return (JAMToDetik(J1)==JAMToDetik(J2));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return (JAMToDetik(J1)!=JAMToDetik(J2));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    return (JAMToDetik(J1)<JAMToDetik(J2));
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
{
    return (JAMToDetik(J1)>JAMToDetik(J2));
}
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    int detik;
    detik = JAMToDetik(J);
    detik = detik + 1;
    return (DetikToJAM(detik));
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    int detik;
    detik = JAMToDetik(J);
    detik = detik + N;
    return (DetikToJAM(detik));
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    int detik;
    detik = JAMToDetik(J);
    detik = detik - 1;
    return (DetikToJAM(detik));
}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
    int detik;
    detik = JAMToDetik(J);
    detik = detik - N;
    return (DetikToJAM(detik));
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    int detikAw, detikAkh, n;
    detikAw = JAMToDetik(JAw);
    detikAkh = JAMToDetik(JAkh);
    if (detikAw > detikAkh)
    {
        n = 3600;
    }else
    {
        n = detikAkh - detikAw;
    }
    return n;
}
void CetakDurasi(long Durasi)
{
	int x, y;
	x = Durasi % 86400;
	x = x/3600;
	y = x % 3600;
	y = y / 60;
	printf ("X = %d  Y = %d \n", x, y);
}
#endif
