/* Prosedur Serve */
/* Dapat dipanggil jika di dekat antrian (pengecekan dilakukan diluar procedure serve)*/
/* dilaksanakan saat main phase */
/* Serve memakan waktu (tergantng wahananya mungkin)*/
/* Setelah serve berhasil uang player bertambah, sisa waktu berkurang */


#include <stdlib.h>
#include <stdio.h>

/* yang lain yang mungkin di include
jam.h
queue.h

*/
void Serve(Player *Player, Queue *Q, Str Namawahana)
{
    printf("//\tServing Costumer\t//\n");
    infotype del;
    Dequeue(Q,&del);
    *Player.money = *Player.money + Namawahana.cost // ??
    // Time nya maju
}
