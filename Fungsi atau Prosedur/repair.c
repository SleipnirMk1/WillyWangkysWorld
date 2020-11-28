#define REPAIRTIME 
#define REPAIRCOST 40

void repair (Wahana *W, StackAction S, ListWahana W1, Player P)
{
    if ()
    {
        if (IsAdaBroken)
        {
            printf("// Memperbaiki %s //\n", nama(W));
            
            condition(W) = true;
            Money(P) -= REPAIRCOST;
        }
        else
        {
            printf("Wahana ini sedang tidak rusak\n");
        }
        
    }
    else
    {
        printf("Tidak ada wahana di samping kanan atau kiri\n");
    }
    
}