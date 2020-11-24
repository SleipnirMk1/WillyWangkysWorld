void prepare(Queue Q)
{
	while (!IsQueueEmpty(Q))
	{
		Dequeue(Q); /*Kosongkan antrian*/
	}
	Current_Time = MakeJAM(21,00,00);
	NextTime = 'Opening Time : 09:00\n';
}

