/* File Dirver Stack */

#include <stdio.h>
#include <stdlib.h>
#include "..\custom_adt\stackaction.c"
#include "..\custom_adt\player.c"
#include "..\Jam\jam.c"
#include "..\Point\point.c"
#include "..\mesinkata\mesinkata.c"
#include "boolean.h"

int main ()
{
    Action A;
    StackAction S;
    CreateEmptyStackAction(&S);
    if(IsEmptyStackAction(S)){
        printf("Stack masih kosong \n");
    }

    ActionName(A) = SetKalimat("Driver");
    SetKata(&ActionType(A), "Testing1");
    ActionTime(A) = 100;
    ActionAmount(A) = 10;
    ActionPrice(A) = 50;
    Wood(ActionMaterialCost(A)) = 5;
    Stone(ActionMaterialCost(A)) = 5;
    Iron(ActionMaterialCost(A)) = 5;
    ActionPosition(A) = MakePOINT(1, 1, 1);

    PushAction(&S,A);
    if(IsEmptyStackAction(S)){
        printf("Seharusnya tidak koson !!\n");
    }

    ActionName(A) = SetKalimat("Driver");
    SetKata(&ActionType(A), "Testing2");
    ActionTime(A) = 99;
    ActionAmount(A) = 9;
    ActionPrice(A) = 49;
    Wood(ActionMaterialCost(A)) = 9;
    Stone(ActionMaterialCost(A)) = 9;
    Iron(ActionMaterialCost(A)) = 9;
    ActionPosition(A) = MakePOINT(9, 9, 9);
    PushAction(&S,A);


    while(!IsEmptyStackAction(S))
    {
        PopAction(&S, &A);
        printf("%s",ActionName(A));
        printf("%s",ActionType(A));
        printf("%d",ActionTime(A));
        printf("%d",ActionAmount(A));
        printf("%d",ActionPrice(A));
        printf("%d",Wood(ActionMaterialCost(A)));
        printf("%d",Stone(ActionMaterialCost(A)));
        printf("%d",Iron(ActionMaterialCost(A)));
        TulisPOINT(ActionPosition(A));
    }


    return 0;
}
