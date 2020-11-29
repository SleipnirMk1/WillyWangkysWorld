void intro()
{
    printf(" ,ggg,      gg      ,gg                                   ,ggg,      gg      ,gg    _     _       _                                         d8'          \n");
    printf("dP""Y8a     88     ,8P       ,dPYb, ,dPYb,               dP""Y8a     88     ,8P    ' )   /       //   /               ,dPYb,               d8'            \n");
    printf("Yb, `88     88     d8'       IP'`Yb IP'`Yb               Yb, `88     88     d8'     / / /__ __  // __/                IP'`Yb              ""\n");
    printf(" `'  88     88     88   gg   I8  8I I8  8I                `'  88     88     88     (_(_/(_)/ (_</_(_/_                I8  8I\n");
    printf("     88     88     88   ''   I8  8' I8  8'                    88     88     88                                        I8  8bgg,\n");
    printf("     88     88     88   gg   I8 dP  I8 dP  gg     gg          88     88     88    ,gggg,gg   ,ggg,,ggg,     ,gggg,gg  I8 dP" "8  gg     gg    ,g,\n");
    printf("     88     88     88   88   I8dP   I8dP   I8     8I          88     88     88   dP'  'Y8I  ,8' '8P' '8,   dP'  'Y8I  I8d8bggP'  I8     8I   ,8'8,\n");
    printf("     Y8    ,88,    8P   88   I8P    I8P    I8,   ,8I          Y8    ,88,    8P  i8'    ,8I  I8   8I   8I  i8'    ,8I  I8P' 'Yb,  I8,   ,8I  ,8'  Yb\n");
    printf("      Yb,,d8''8b,,dP  _,88,_,d8b,_ ,d8b,_ ,d8b, ,d8I           Yb,,d8''8b,,dP  ,d8,   ,d8b,,dP   8I   Yb,,d8,   ,d8I ,d8    `Yb,,d8b, ,d8I ,8'_   8)\n");
    printf("       '88'    '88'   8P''Y88P''Y888P''Y88P''Y88P'888           '88'    '88'   P'Y8888P'`Y88P'   8I   `Y8P'Y8888P'88888P      Y8P''Y88P'888P' 'YY8P8P\n");
    printf("                                                ,d8I'                                                           ,d8I'                 ,d8I'\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::,dP'8I::::::::::::::::::::::::::::::::::::::::::::::::::::::::::,dP'8I::::::::::::::::,dP'8I::::::::::: \n");
    printf("                                             ,8'  8I                                                         ,8'  8I               ,8'  8I\n");
    printf("                                             I8   8I                                                         I8   8I               I8   8I\n");
    printf("                                             `8, ,8I                                                         `8, ,8I               `8, ,8I\n");
    printf("                                              `Y8P'                                                           `Y8P'                 `Y8P'\n");
    printf("\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":                    |:                    |:                     |:                |:                :\n");
    printf(":      NEW GAME      |:    COMING SOON     |:     COMING SOON     |:      HELP      |:      EXIT      :\n");
    printf(":                    |:                    |:                     |:                |:                :\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    /* sesuaikan lagi itu menu nya dengan inputnya */
}

void help()
{
    int input_help;
    boolean end = false;

    while (!end)
    {
        printf(" 1. getstarted\n");
        printf(" 2. cmdgame\n");
        printf(" 3. creditgame\n");
        printf(" 4. quithelp\n");
        printf(" [Willy Wangky Bot] Can I help you? : <choose help number>\n");
        scanf(" >> %d", input_help);
        if (input_help == 1)
        {
            
        }
        else if (input_help == 2)
        {
            printf(" [Willy Wangky Bot] Here is our list command game : \n");
            printf("\n");
            printf(" I. Movement \n");
            printf(" ================================================ \n");
            printf(" 1. w : move up one tile \n");
            printf(" 2. a : move left one tile \n");
            printf(" 3. s : move down one tile \n");
            printf(" 4. d : move right one tile \n");
            printf("\n");
            printf(" II. In-Game \n");
            printf(" ================================================ \n");
            printf(" \n");
            printf("\n");
            printf(" III. Office \n");
            printf(" ================================================ \n");
            printf(" \n");
            printf("\n");
            printf(" IV. Preparation Phase \n");
            printf(" ================================================ \n");
            printf(" \n");
            printf("\n");
            printf(" V. Main Phase \n");
            printf(" ================================================ \n");
            printf(" \n");
        }
        else if (input_help == 3)
        {
            printf(" [Willy Wangky Bot] This game was credited by : \n");
            printf("\n");
            printf(" 1. Ilyasa Salafi Putra Jamal \n");
            printf(" 2. Yudi Alfayat \n");
            printf(" 3. Giant Andreas Tambunan \n");
            printf(" 4. Benidictus Galih Mahar Putra \n");
            printf(" 5. Raffi Fadhlurrahman Putra Rahiem \n");
        }
        else if (input_help == 4)
        {
            printf("Have fun~ !\n");
            end = true;
        }
        else
        {
            printf("There is no such command in the help menu\n");
        }
        printf("\n");
    }
    
}