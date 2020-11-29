/* Prosedur Serve */
/* Dapat dipanggil jika di dekat antrian (pengecekan dilakukan diluar procedure serve)*/
/* dilaksanakan saat main phase */
/* Serve memakan waktu (tergantng wahananya mungkin)*/
/* Setelah serve berhasil uang player bertambah, sisa waktu berkurang */


#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "mesinkata.h"
#include "queueAntrian.h"
#include "boolean.h"

/* ketika command serve di input langsung memnaggil prosedur serve */
/* nama wahana di input di prosedur serve */

void Serve()
{
    Kalimat inputnamaWahana = GetKalimat();
    /* Antiran punya posisition ? */
    /* pengecekan apakah player di dekat antrian belum */
    int i ;
    boolean ada = false;
    while ((i<NbWahanaDimiliki) && !(ada)){
        if(IsEQKalimat(inputnamaWahana, Nama(ElmtWahana(ListWahanaDimiliki, i))){
            ada = true;
        }
        else{
            i++;
        }
    }

    if(ada){    // mengecek jika input wahana sesuai
        if(IsEQKalimat(inputnamaWahana, InfoHead(Antrian))){    // mengecek input nama wahana sesuai dengan head antrian
            DequeueAntrian(&Antrian, &inputnamaWahana);
            addMoney(&P, Price(ElmtWahana(ListWahanaDimiliki, i));
            addTime(&P, (long) PlayTime(ElmtWahana(ListWahanaDimiliki, i));
        }
        else{
            printf("Nama wahana tidak sesuai dengan antrian\n");
        }
    }
    else{
        printf("Tidak ada wahan yang dimaksud\n");
    }

}
