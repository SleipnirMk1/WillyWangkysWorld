#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"

void execute (StackAction *S)
{
    /* Kamus lokal */
    Stack StackExecute;
    infotype Command;

    /*Algoritma*/
    if (!IsEmpty(*S))
    {
        while (!IsEmpty(*S))
        {
            Pop(&S, &Command);
            Push(&StackExecute, &Command);
        }
        while (!IsEmpty(StackExecute))
        {
            Pop(&StackExecute, &cmd);
            if (cmd == "build")
            {
                build;
            }
            else if (cmd == "updgrade")
            {
                upgrade;
            }
            else
            {
                buy;
            }
            
        }

    }
    main(*S);
}