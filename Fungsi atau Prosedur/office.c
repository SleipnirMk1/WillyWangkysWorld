#include "listlinierwahana.h"
#include "boolean.h"
#include "wahana.h"

void office(ListWahana list_of_built_wahana)
{
    char in[128];
    printf("Detail wahana apa yang ingin Anda lihat: \n");
    scanf("%s\n", &in);

    boolean found = false;
    address Elmt = First(list_of_built_wahana);
    while (Elmt != Nil && !found)
    {
        if (NamaW(Info(Elmt)) == in)
        {
            found = true;
        }
        else
        {
            Elmt = Next(Elmt);
        }
        
    }

    if (found)
    {
        Detail(Info(Elmt));
    }
    else
    {
        printf("Informasi wahana tidak tersedia\n");
    }
}

void Detail(WAHANA Wahana)
{
    printf("Nama Wahana: %s\n", NamaW(Wahana));
    printf("Tipe Wahana: %s\n", Tipe(Wahana));
    printf("Biaya Uang: %s\n", Biaya(Wahana));
    printf("Keperluan Kayu: %s\n", Wood(Wahana));
    printf("Keperluan Batuan: %s\n", Stone(Wahana));
    printf("Keperluan Besi: %s\n", Iron(Wahana));
    printf("Lokasi Wahana: %s\n", Lokasi(Wahana));
    printf("Kapasitas Isi Wahana: %s\n", Kapasitas(Wahana));
    printf("Durasi Wahana: %s\n", Durasi(Wahana));
    printf("Keuntungan tiap pelanggan: %s\n", Profit(Wahana));
    printf("Deskripsi Wahana: %s\n", Deskripsi(Wahana));
    printf("Total penggunaan: %s\n", TotalNaik(Wahana));
    printf("Total keuntungan: %s\n", TotalProfit(Wahana));
    printf("Penggunaan hari ini: %s\n", TodayNaik(Wahana));
    printf("keuntungan hari ini: %s\n", TodayProfit(Wahana));
}











