#include "arraywahana.h"
#include "boolean.h"
#include "wahana.h"

void office(ArrayWahana list_of_built_wahana)
{
    char in[128];
    printf("Detail wahana apa yang ingin Anda lihat: \n");
    scanf("%s\n", &in);

    Idxtype p = Search1Wahana(list_of_built_wahana, in);

    if (p != IdxUndef)
    {
        Detail(Elmt(list_of_built_wahana, p));
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











