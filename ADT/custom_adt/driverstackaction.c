#include <stdio.h>
#include "stackaction.h"
#include "boolean.h"

int main()
{
    /* Kamus */ 
    StackAction S;
    Action temp;

    /* Algoritma */ 
    CreateEmptyStackAction(&S);

    if (IsEmptyStackAction(S))
    {
        printf("stack kosong !\n");
    }
    else
    {
        printf("stack tidak kosong !\n");
    }

    PushAction(&S, );


    PopAction(&S, &temp);
    printf

    
    PushAction(&S, );
    PushAction(&S, );
    InversStack(&S);


    printf("Total time action : %d\n", TotalTimeAction(S));
    printf("Total price : %d\n", TotalPrice(S));

    return 0;
}