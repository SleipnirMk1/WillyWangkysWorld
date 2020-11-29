#include <stdio.h>
#include "boolean.h"
#include "jam.h"

int main()
{
    /* Kamus */ 
    JAM Clock, Clock1, ClockT, ClockS, ClockD;
    long duration;

    /* Algoritma */
    /* membuat jam */
    Clock = MakeJAM(0, 0, 0);
    TulisJAM(Clock);

    printf("next test\n");
    /* valid jam */
    ClockT = MakeJAM(-1, 25, 60);
    TulisJAM(ClockT);
    if(IsJAMValid(Hour(ClockT), Minute(ClockT), Second(ClockT)))
    {
        printf("valid !");
    }
    else
    {
        printf("tidak valid !");
    }

    printf("next test\n");
    /* buat jam custom */
    BacaJAM(&Clock1);
    TulisJAM(Clock1);

    /* Jam to detik dan detik to jam */
    printf("next test\n");
    TulisJAM(Clock1);
    printf("Jam %d = Detik : %ld\n", Hour(Clock1), JAMToDetik(Clock1));
    TulisJAM(DetikToJAM(90000));

    /* jam ekival */
    printf("next test\n");
    ClockS = MakeJAM(0, 0, 0);
    if (JEQ(Clock, ClockS))
    {
        printf("eqival !");
    }
    else
    {
        printf("tidak eqival !");
    }
    
    /* jam not ekival */
    printf("next test\n");
    ClockD = MakeJAM(5, 0, 0);
    if (JNEQ(Clock, ClockD))
    {
        printf("tidak eqival !");
    }
    else
    {
        printf("eqival !");
    }
    
    /* j1 < j2 */
    printf("next test\n");
    ClockD = MakeJAM(5, 0, 0);
    if (JLT(Clock, ClockD))
    {
        printf("Clock lebih kecil !");
    }
    else
    {
        printf("ClockD lebih kecil !");
    }

    /* j1 > j2 */
    printf("next test\n");
    ClockD = MakeJAM(5, 0, 0);
    if (JGT(Clock, ClockD))
    {
        printf("Clock lebih besar !");
    }
    else
    {
        printf("ClockD lebih besar !");
    }

    /* nextdetik */
    printf("next test\n");
    NextDetik(Clock);
    TulisJAM(Clock);

    /* next n detik */
    printf("next test\n");
    NextNDetik(Clock, 3600);
    TulisJAM(Clock);

    /* prevdetik */
    printf("next test\n");
    PrevDetik(Clock);
    TulisJAM(Clock);

    /* prev n detik */
    printf("next test\n");
    PrevNDetik(Clock, 3600);
    TulisJAM(Clock);

    /* Buat dan cetak durasi */
    printf("next test\n");
    duration = Durasi(Clock, ClockD);
    CetakDurasi(duration);

    return 0;
}