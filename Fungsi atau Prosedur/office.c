#include "../ADT/custom_adt/arraywahana.h"
#include "../ADT/custom_adt/wahana.h"
#include "../ADT/custom_adt/boolean.h"
#include "../ADT/mesinkata/mesinkata.h"

void office()
{
    printf("Detail wahana apa yang ingin Anda lihat: \n");

    Kalimat nama = GetKalimat();
    WAHANA Wahana;
    found = false;
    while (!found && i <= 100)
    {
        if (IsEQKalimat(nama, ListWahanaYandDimiliki[int n].Name))
        {
            found = true;
            Wahana = ListWahanaYandDimiliki[i];
        }
        else
        {
            i++;
        }
        
    }
    
    if (found)
    {
        Detail(Wahana));
        Report(Wahana);
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
    if (Condition(Wahana))
    {
        printf("Kondisi Wahana: Tidak rusak", );
    }
    else
    {
        printf("Kondisi Wahana: Rusak", );   
    }
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

void Report(WAHANA Wahana)
{
    printf("Total Jumlah Pengunjung: %d\n", TotalNaik(Wahana));
    printf("Total Penghasilan: %d\n", TotalProfit(Wahana));
    printf("Total Jumlah Pengunjung Hari Ini: %d\n", TodayNaik(Wahana));
    printf("Total Jumlah Pengunjung Hari Ini: %d\n", TodayProfit(Wahana));
}











