/* File: driverarraywahana.c */

#include <stdio.h>
#include "boolean.h"
#include "arraywahana.h"

int main ()
{
    ArrayWahana T, T2;
    MakeEmptyWahana(&T);

    int a = NbElmtWahana(T);
    printf("%d\n", a);

    a = MaxNbElWahana(T);
    printf("%d\n", a);

    a = GetFirstIdxWahana(T);
    printf("%d\n", a);

    a = GetLastIdxWahana(T);
    printf("%d\n", a);

    boolean b = IsIdxValidWahana(T,1);
    if(b)
    {
        printf("Yes\n");
    }

    b = IsIdxEffWahana(T,1);
    if(b)
    {
        printf("Yes\n");
    }

    b = IsEmptyWahana(T);
    if(b)
    {
        printf("Yes\n");
    }

    b = IsFullWahana(T);
    if(b)
    {
        printf("Yes\n");
    }

    TulisIsiTabWahana(T);

    MakeEmptyWahana(&T2);
    b = IsEQWahana(T,T2);
    if(b)
    {
        printf("Yes\n");
    }

    a = Search1Wahana(T, 1);
    printf("%d\n", a);

    b = SearchBWahana(T, 1);
    if(b)
    {
        printf("Yes\n");
    }

    return 0;
}
