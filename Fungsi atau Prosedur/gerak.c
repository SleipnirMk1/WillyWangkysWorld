void gerak(char X)
{
	if ((X == w)|()X == W))
	{
		if (!IsWall(PosX(P),PosY(P) + 1))	
		{
			PosX(P)	= PosX(P);
			PosY(P)	= PosY(P) + 1;
		)
	}else if ((X == a)|(X == A))
	{
		if (!IsWall(PosX(P)-1,PosY(P)))
		{
			PosX(P)	= PosX(P) - 1;
			PosY(P)	= PosY(P);
		)
	}else if ((X == s)|(X == S))
	{
		if (!IsWall(PosX(P),PosY(P) - 1)
		{
			PosX(P)	= PosX(P);
			PosY(P)	= PosY(P) - 1;
		}
	}else if ((X == d)|(X == D))
	{
		if (!IsWall(PosX(P) + 1,PosY(P))
		{
			PosX(P)	= PosX(P) + 1;
			PosY(P)	= PosY(P);

		}
		
	}
}

