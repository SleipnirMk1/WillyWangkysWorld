/* File     : matriks.c */
/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
   NBrsEff(*M) = NB;
   NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
   return ((i <= BrsMax) && (j <= KolMax) && (i >= BrsMin) && (i >= KolMin));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
   indeks a = BrsMin;
   return a;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
   indeks a = KolMin;
   return a;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
   indeks a = NBrsEff(M) - 1;
   return a;
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
   indeks a = NKolEff(M) - 1;
   return a;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
   return ((i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M)));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
   return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
   MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);

   *MHsl = MIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
A B C
D E F
G H I
*/
{
   indeks i, j;
   ElType a;
   MakeMATRIKS(NB, NK, M);

   for (i = GetFirstIdxBrs(*M); i < NB; ++i)
   {
      for (j = GetFirstIdxKol(*M); j < NK; ++j)
      {
         scanf("%c ", &a);
         Elmt(*M, i, j) = a;
      }

      printf("\n");
   }

}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
A B C
D E F
G H I
*/
{
    indeks i;
    indeks j;
    for (i=GetFirstIdxBrs(M); i<= GetLastIdxBrs(M); i++){
        for (j=GetFirstIdxKol(M); j<= GetLastIdxKol(M); j++){
            if (j == GetLastIdxKol(M)){printf("%c",Elmt(M,i,j));}
            else{
                printf("%c ",Elmt(M,i,j));
            }
        }
        if(i != GetLastIdxBrs(M)){printf("\n");}
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
   indeks i, j;

   if (NBElmt(M1) == NBElmt(M2))
   {
      for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); ++i)
      {
         for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); ++j)
         {
            if (Elmt(M1,i,j) != Elmt(M2,i,j))
            {
               return false;
            }
         }
      }
      return true;
   } else {
      return false;
   }
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
   return (!EQ(M1,M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
   return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
   return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
   return (NBrsEff(M) == NKolEff(M));
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
   indeks i, j;
   float count;

   for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); ++i)
   {
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); ++j)
      {
         if (Elmt(M,i,j) != 0)
         {
            ++count;
         }
      }
   }

   return ((count / NBElmt(M)) <= 0.05);
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
   indeks i, j;
   MATRIKS M2;
   ElType temp;
   MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &M2);
   CopyMATRIKS(*M, &M2);

   for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); ++i)
   {
      for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); ++j)
      {
         Elmt(*M,i,j) = Elmt(M2,j,i);
      }
   }
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
   indeks j;
   int count = 0;

   for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); ++j)
   {
      if (Elmt(M,i,j) == X)
      {
         ++count;
      }
   }
   return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
   indeks i;
   int count = 0;

   for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); ++i)
   {
      if (Elmt(M,i,j) == X)
      {
         ++count;
      }
   }
   return count;
}

