void prepare(Queue Q)
{
	while (!IsQueueEmpty(Q))
	{
		Dequeue(Q); /*Kosongkan antrian*/
	}
	printf ('// Lanjut ke Preparation Phase //\n');
	printf ('Main phase day ', P.day, '\n');
	CetakMap;
	
	/*printf ('Legend: \n');
	printf ('A = Antrian\n')
	printf ('P = Player\n')
	printf ('W = Wahana\n')
	printf ('O = Office\n')
	printf ('<, ^, >, v = Gerbang\n')
		
	printf ('Nama : '); printf(P.nama);
	printf ('Money : '); printf(P.money);*/
	
	/*Current_Time = MakeJAM(09,00,00);
	printf ('Current Time : '); TulisJAM(Current_Time); printf('\n');
	Next_Time = MakeJAM(21,00,00);
	printf ('Opening Time : '); TulisJAM(Next_Time); printf('\n');
	Time_Remaining = Durasi(Current_Time, Next_Time);
	printf ('Time Remaining: '); CetakDurasi(Time_Remaining); printf('\n');*/
	
	/*printf ('Total aksi yang akan dilakukan: 0');
	printf ('Total waktu yang dibutuhkan: 0');
	printf ('Total uang yang dibutuhkan: 0');*/
}

