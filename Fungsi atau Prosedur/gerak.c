boolean IsWall(float X, float Y)
{
	return (X == 0)|(X == 19)|(Y == 19)|(Y == 0);
}
boolean IsGerbang(float X, float Y, int A)
{
	if (A == 1)
	{
		return ((X == 19) && (Y == 4))|((X == 9)&&(Y == 9));
	}
	else if (A == 2)
	{
		return ((X == 0) && (Y == 4))|((X == 9)&&(Y == 9));
	}
	else if (A == 3)
	{
		return ((X == 19) && (Y == 4))|((X == 9)&&(Y == 0));
	}
	else if (A == 4)
	{
		return ((X == 0) && (Y == 4))|((X == 9)&&(Y == 0));
	}
}
void gerak(char X, P)
{
	if (X == 0)
	{
		if (!IsWall(Absis(P),Ordinat(P) + 1))
		{
			if(IsGerbang(Absis(P),Ordinat(P) + 1, Area(P)))
			{
				/*Point dengan Ordinat == 0*/
				if (Area(P) == 3)
				{
					Absis(P) = 9;
					Ordinat(P) = 8;
					Area(P) = 1;
				}
				else if (Area(P) == 4)
				{
					
					Absis(P) = 9;
					Ordinat(P) = 8;
					Area(P) = 2;
				}
			}
			else
			{
				Geser (P, 0, 1, 0);
			}
		}
	}
	else if (X == 1)
	{
		if (!IsWall(Absis(P)-1,Ordinat(P)))
		{
			if(IsGerbang(Absis(P),Ordinat(P) + 1, Area(P)))
			{
				/*Point dengan Absis == 0*/
				if (Area(P) == 2)
				{
					Absis(P) = 18;
					Ordinat(P) = 4;
					Area(P) = 1;
				}
				else if (Area(P) == 4)
				{
					
					Absis(P) = 18;
					Ordinat(P) = 4;
					Area(P) = 3;
				}
			}
			else
			{
				Geser (P, -1, 0, 0);
			}
		}
	}
	else if (X == 2)
	{
		if (!IsWall(Absis(P),Ordinat(P) - 1))
		{
			if(IsGerbang(Absis(P),Ordinat(P) + 1, Area(P)))
			{
				/*Point dengan Ordinat == 9*/
				if (Area(P) == 2)
				{
					Absis(P) = 9;
					Ordinat(P) = 1;
					Area(P) = 4;
				}
				else if (Area(P) == 1)
				{
					
					Absis(P) = 9;
					Ordinat(P) = 1;
					Area(P) = 3;
				}
			}
			else
			{
				Geser (P, 0, -1, 0);
			}
		}
	}
	else if (X == 3)
	{
		if (!IsWall(Absis(P) + 1,Ordinat(P)))
		{
			if(IsGerbang(Absis(P),Ordinat(P) + 1, Area)))
			{
				/*Point dengan Absis == 19*/
				if (Area(P) == 1)
				{
					Absis(P) = 1;
					Ordinat(P) = 4;
					Area(P) = 2;
				}
				else if (Area(P) == 3)
				{
					
					Absis(P) = 1;
					Ordinat(P) = 4;
					Area(P) = 4;
				}
			}
			else
			{
				Geser (P, 1, 0, 0);
			}
		}
		
	}
}
